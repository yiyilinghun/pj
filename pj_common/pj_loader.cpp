#include "Precompiled.h"
#include "pj_loader.h"

#define WAS_MAKE_ARGB(c, a) (a << 24) + (c << 8 & 0xf80000) + (c << 5 & 0x7fc00) + (((c << 3 | (c & 7)) & 0x3ff))

std::shared_ptr<pjResManager> g_ms_pjResManager = nullptr;
pjResManager& pj_GetResManager()
{
    if (!g_ms_pjResManager)
    {
        g_ms_pjResManager.reset(LAMBDA_AUTO_NEW_DELETE(pjResManager));
    }
    return *g_ms_pjResManager.get();
}

inline Boolean
xyReadFile(QString filename, quint32 filekey, QHash<quint64, xyUnit>& hashReses)
{
    try
    {
        QFile xFile(filename);

        if (!xFile.open(QIODevice::ReadOnly))
        {
            qCritical(QString(u8"打开资源文件失败:%1").arg(filename).toStdString().c_str());
            return False;
        }

        QDataStream xStream(&xFile);
        xStream.setByteOrder(QDataStream::LittleEndian);
        xFile.seek(0);

        quint32 xFileHeadFlag = 0;
        xStream >> xFileHeadFlag;
        qDebug(QString(u8"读取文件头标记:%1").arg(filename).toStdString().c_str());
        if (xFileHeadFlag != 0x57444650)
        {
            qCritical(QString(u8"xFileHeadFlag != 0x57444650:%1").arg(filename).toStdString().c_str());
            return False;
        }

        quint32 xUnitCount;
        quint32 xCatalogListAddr;

        xStream >> xUnitCount;
        qDebug(QString(u8"读取单元数量:%1").arg(filename).toStdString().c_str());

        xStream >> xCatalogListAddr;
        qDebug(QString(u8"读取单元地址:%1").arg(filename).toStdString().c_str());

        xFile.seek(xCatalogListAddr);

        for (quint32 i = 0; i < xUnitCount; i++)
        {
            xyUnit tempUnit;
            xStream >> tempUnit.m_UnitFileInfo;
            qDebug(QString(u8"读取单元信息:%1(%2)").arg(filename).arg(xUnitCount).toStdString().c_str());
            quint64 xKey = filekey;
            xKey <<= 32;
            xKey += tempUnit.m_UnitFileInfo.m_Key;
            hashReses[xKey] = tempUnit;
        }

        xFile.close();
        return True;
    }
    catch (...) {}
    return False;
}

inline void
xyParseSome(QDataStream& xStream, quint32* lpTextureData, qint32 xTextureWidth,
    WPixels& xPalette, qint32 xFrameOffset, qint32* xLineOffsets,
    quint32 xFrameWidth, quint32 xFrameHeight, quint16 imageHeaderSize, Boolean& IsInterlacedgh)
{
    //QDataStream xStream(&xBuffer);
    quint32 xLimitWidth = xFrameWidth;
    quint32 xLimitHeight = xFrameHeight;

    IsInterlacedgh = True;
    for (quint32 xIndexY = 0; xIndexY < xFrameHeight; xIndexY++)
    {
        xStream.device()->seek(xLineOffsets[xIndexY] + xFrameOffset + imageHeaderSize + 4);
        for (quint32 xIndexX = 0; xIndexX < xFrameWidth;)
        {
            uint8_t xTemp;
            xStream >> xTemp;
            quint32 xPixelTemp = (quint32)xTemp;

            // 象素行结束
            if (xPixelTemp == 0) { break; }

            switch (xPixelTemp & 0xC0)
            {
                case 0:
                {
                    if (xIndexY % 2) { IsInterlacedgh = False; }

                    if (xPixelTemp & 0x20)
                    {
                        quint32 i = (quint32)(xStream >> xTemp, xTemp);
                        quint32 x = xIndexX;
                        quint32 y = xIndexY;
                        quint32 a = (xPixelTemp & 0x1F);
                        if (x >= 0 && x < xLimitWidth && y >= 0 && y < xLimitHeight)
                        {
                            if (a) { a = (a << 3) - 7; lpTextureData[xTextureWidth * y + x] = WAS_MAKE_ARGB(xPalette.m_Palette[i].m_Color, a); }
                            xIndexX++;
                        }
                    }
                    else if (xPixelTemp)
                    {
                        quint32 c = xPixelTemp & 0x1F;
                        quint32 a = (quint32)(xStream >> xTemp, xTemp);
                        quint32 i = (quint32)(xStream >> xTemp, xTemp);
                        if (a) { a = (a << 3) - 7; }
                        for (quint32 xIndex = 0; xIndex < c; xIndex++)
                        {
                            quint32 x = xIndexX;
                            quint32 y = xIndexY;
                            if (x >= 0 && x < xLimitWidth && y >= 0 && y < xLimitHeight)
                            {
                                lpTextureData[xTextureWidth * y + x] = WAS_MAKE_ARGB(xPalette.m_Palette[i].m_Color, a);
                                xIndexX++;
                            }
                        }
                    }
                    else
                    {
                        xIndexX = xFrameWidth;
                    }
                }break;

                case 0x40:
                {
                    if (xIndexY % 2) { IsInterlacedgh = False; }

                    quint32 c = xPixelTemp & 0x3F;
                    for (quint32 xIndex = 0; xIndex < c; xIndex++)
                    {
                        quint32 i = (quint32)(xStream >> xTemp, xTemp);
                        quint32 x = xIndexX;
                        quint32 y = xIndexY;
                        if (x >= 0 && x < xLimitWidth && y >= 0 && y < xLimitHeight)
                        {
                            //lpTextureData[xTextureWidth * y + x] = WAS_MAKE_ARGB(xPalette.m_Palette[i].m_Color, 0x7F);
                            lpTextureData[xTextureWidth * y + x] = WAS_MAKE_ARGB(xPalette.m_Palette[i].m_Color, 0xFF);
                            xIndexX++;
                        }
                    }
                }break;

                case 0x80:
                {
                    if (xIndexY % 2) { IsInterlacedgh = False; }

                    quint32 c = xPixelTemp & 0x3F;
                    quint32 i = (quint32)(xStream >> xTemp, xTemp);
                    for (quint32 xIndex = 0; xIndex < c; xIndex++)
                    {
                        quint32 x = xIndexX;
                        quint32 y = xIndexY;
                        if (x >= 0 && x < xLimitWidth && y >= 0 && y < xLimitHeight)
                        {
                            lpTextureData[xTextureWidth * y + x] = WAS_MAKE_ARGB(xPalette.m_Palette[i].m_Color, 0xFF);
                            xIndexX++;
                        }
                    }
                }break;
                default: { xIndexX += (xPixelTemp & 0x3F); }break;
            }
        }
    }
}

//inline Boolean
//xySetTexturePixels(LPVOID hTextureHandle, quint32* lpPixels, qint32 xWidth, qint32 xHeight)
//{
//    qint32 xTextureRowPitch;
//    LPBYTE xTextureDataPtr = (LPBYTE)g_CurrentAPI->BeginModifyTexture(hTextureHandle, xWidth, xHeight, &xTextureRowPitch);
//    if (!xTextureDataPtr) { return False; }
//
//    LPBYTE xDst = xTextureDataPtr;
//    if (g_Graphics->GetRenderer() == kUnityGfxRendererD3D9)
//    {
//        for (qint32 y = 0; y < xHeight; y++)
//        {
//            LPBYTE xPtr = xDst;
//            for (qint32 x = 0; x < xWidth; x++)
//            {
//                // Write the texture pixel
//                LPBYTE xPixel = (LPBYTE)&(lpPixels[(xHeight - y)*xWidth + x]);
//
//                xPtr[3] = xPixel[3]; // A
//                xPtr[0] = xPixel[0]; // B
//                xPtr[1] = xPixel[1]; // G
//                xPtr[2] = xPixel[2]; // R
//
//                xPtr += 4;
//            }
//            xDst += xTextureRowPitch;
//        }
//    }
//    else
//    {
//        for (qint32 y = 0; y < xHeight; y++)
//        {
//            LPBYTE xPtr = xDst;
//            for (qint32 x = 0; x < xWidth; x++)
//            {
//                // Write the texture pixel
//                LPBYTE xPixel = (LPBYTE)&(lpPixels[(xHeight - y)*xWidth + x]);
//
//                xPtr[3] = xPixel[3]; // A
//                xPtr[0] = xPixel[2]; // R
//                xPtr[1] = xPixel[1]; // G
//                xPtr[2] = xPixel[0]; // B
//
//                xPtr += 4;
//            }
//            xDst += xTextureRowPitch;
//        }
//    }
//
//    g_CurrentAPI->EndModifyTexture(hTextureHandle, xWidth, xHeight, xTextureRowPitch, xTextureDataPtr);
//
//    return True;
//}



// 资源文件容器
Boolean pjResManager::pjLoadFile(QString&& filename, quint32& filekey)
{
    QString md5FileName;
    md5FileName.append(QCryptographicHash::hash(filename.toUtf8(), QCryptographicHash::Md5).toHex());
    md5FileName = md5FileName.mid(0, 8);
    filekey = md5FileName.toULong(nullptr, 16);

    if (m_hashReskeyResFilename.find(filekey) != m_hashReskeyResFilename.end())
    {
        return True;
    }
    else
    {
        if (xyReadFile(filename, filekey, m_hashReses))
        {
            m_hashReskeyResFilename[filekey] = filename;
            return True;
        }
        return False;
    }
}

// 获取资源总数
quint32 pjResManager::pjGetUnitSum() { return (quint32)m_hashReses.size(); }


// 获取动画纹理数量(64位前32位代表朝向数量,后32位代表帧数)
Boolean pjResManager::pjGetWasTextureSum(quint64 unitKey, quint64 texSum, quint64 texSize)
{
    // 资源不存在
    if (m_hashReses.find(unitKey) == m_hashReses.end()) { return 0; }

    // 资源文件对应表不存在
    if (m_hashReskeyResFilename.find((quint32)(unitKey >> 32)) == m_hashReskeyResFilename.end()) { return 0; }

    // 读取动画数据
    xyUnit& xWdfUnit = m_hashReses[unitKey];
    quint32& xLen = xWdfUnit.m_UnitFileInfo.m_Len;
    try
    {
        QFile xFile(m_hashReskeyResFilename[(quint32)(unitKey >> 32)]);
        //std::shared_ptr<FILE> xFile(
        //    fopen(m_hashReskeyResFilename[(quint32)(unitKey >> 32)].c_str(), "rb"), FAST_LAMBDA_CALL(fclose));
        if (!xFile.open(QIODevice::ReadOnly))
        {
            qCritical(QString(u8"打开资源文件失败:%1").arg(m_hashReskeyResFilename[(quint32)(unitKey >> 32)]).toStdString().c_str());
            return False;
        }
        QDataStream xFileStream(&xFile);
        xFileStream.setByteOrder(QDataStream::LittleEndian);

        //if (xFile == nullptr) { return False; }

        xFile.seek(xWdfUnit.m_UnitFileInfo.m_Addr);
        //fseek(xFile.get(), xWdfUnit.m_UnitFileInfo.m_Addr, SEEK_SET);

        std::shared_ptr<char> xTempdata(LAMBDA_AUTO_NEW_DELETE_ARRAY(char, xLen));
        if (xLen != xFileStream.readRawData(xTempdata.get(), xLen))
        {
            qCritical(QString(u8"读取资源文件失败:%1").arg(m_hashReskeyResFilename[(quint32)(unitKey >> 32)]).toStdString().c_str());
            return False;
        }
        //if (xLen != (quint32)fread(xTempdata.get(), sizeof(uint8_t), xLen, xFile.get())) { return False; }
        //MemoryStream xStream(xTempdata.get(), xLen);
        //xStream.OutSeek(0);
        QBuffer xBuffer;
        xBuffer.setData(xTempdata.get(), xLen);
        QDataStream xUnitStream(&xBuffer);
        xUnitStream.setByteOrder(QDataStream::LittleEndian);

        // 检查文件头标记
        quint16 xFileHeadFlag;
        xUnitStream >> xFileHeadFlag;
        if (xFileHeadFlag != 0x5053)
        {
            qCritical(QString(u8"读取资源文件失败:%1").arg(m_hashReskeyResFilename[(quint32)(unitKey >> 32)]).toStdString().c_str());
            return False;
        }

        quint16 imageHeaderSize;
        quint16 directionCount;
        quint16 frameCount;
        quint16 width;
        quint16 height;

        xUnitStream >> imageHeaderSize >> directionCount >> frameCount >> width >> height;

        texSum = (((quint64)directionCount) << 32) + frameCount;
        texSize = (((quint64)width) << 32) + height;
        return True;
    }
    catch (...) {}
    return False;
}

//// 加载动画列表
//Boolean pjResManager::pjGetWasTextures(xyTextureInfo* ptrTextureInfo, qint32& textureSum)
//{
//    for (qint32 i = 0; i < textureSum; i++)
//    {
//        if (!pjGetWasTexture(ptrTextureInfo[i]))
//        {
//            textureSum = i;
//            return False;
//        }
//    }
//    return True;
//}

// 加载动画
Boolean
pjResManager::pjGetWasTextures(quint64 unitKey, xyTextureInfo& textureInfo, QVector<QImage*>& imageVector)
{
    // 资源不存在
    if (m_hashReses.find(unitKey) == m_hashReses.end()) { return False; }

    // 资源文件对应表不存在
    if (m_hashReskeyResFilename.find((quint32)(unitKey >> 32)) == m_hashReskeyResFilename.end()) { return False; }

    // 读取动画数据
    xyUnit& xWdfUnit = m_hashReses[unitKey];
    quint32& xLen = xWdfUnit.m_UnitFileInfo.m_Len;

    try
    {
        if (!xWdfUnit.m_resOriginalData)
        {
            QFile xFile(m_hashReskeyResFilename[(quint32)(unitKey >> 32)]);
            if (!xFile.open(QIODevice::ReadOnly))
            {
                qCritical(QString(u8"打开资源文件失败:%1").arg(m_hashReskeyResFilename[(quint32)(unitKey >> 32)]).toStdString().c_str());
                return False;
            }
            xFile.seek(xWdfUnit.m_UnitFileInfo.m_Addr);
            QDataStream xFileStream(&xFile);
            xFileStream.setByteOrder(QDataStream::LittleEndian);

            xWdfUnit.m_resOriginalData.reset(LAMBDA_AUTO_NEW_DELETE_ARRAY(char, xLen));
            if (xLen != xFileStream.readRawData(xWdfUnit.m_resOriginalData.get(), xLen))
            {
                qCritical(QString(u8"读取资源文件失败:%1").arg(m_hashReskeyResFilename[(quint32)(unitKey >> 32)]).toStdString().c_str());
                return False;
            }

            QByteArray xByteArray(xWdfUnit.m_resOriginalData.get(), xLen);
            QDataStream xUnitStream(&xByteArray, QIODevice::ReadOnly);
            xUnitStream.setByteOrder(QDataStream::LittleEndian);
            xUnitStream.device()->seek(0);

            if (xUnitStream.atEnd())
            {        // 检查文件头标记
                quint16 xFileHeadFlag;
                xUnitStream >> xFileHeadFlag;
                if (xFileHeadFlag != 0x5053) { return 0; }
            }
            else
            {
                // 检查文件头标记
                quint16 xFileHeadFlag;
                xUnitStream >> xFileHeadFlag;
                if (xFileHeadFlag != 0x5053) { return 0; }
            }

            xUnitStream >> xWdfUnit.m_imageHeaderSize >> xWdfUnit.m_directionCount >> xWdfUnit.m_frameCount >> xWdfUnit.m_width >> xWdfUnit.m_height >> xWdfUnit.m_hotX >> xWdfUnit.m_hotY;

            // 读取帧延迟信息(暂时不需要,先丢弃)
            int16_t xLen = (int16_t)(xWdfUnit.m_imageHeaderSize - 12);
            if (xLen > 0)
            {
                for (qint32 i = 0; i < xLen; i++)
                {
                    uint8_t xDelays = 0;
                    xUnitStream >> xDelays;
                }
            }

            // 读取调色板
            WPixels xPalette = { 0 };
            xUnitStream.device()->seek(xWdfUnit.m_imageHeaderSize + 4);
            //xStream.OutSeek(imageHeaderSize + 4);
            xUnitStream >> xPalette;

            // 读取帧偏移
            std::shared_ptr<qint32> xFrameOffsets(LAMBDA_AUTO_NEW_DELETE_ARRAY(qint32, xWdfUnit.m_directionCount * xWdfUnit.m_frameCount));
            xUnitStream.device()->seek(xWdfUnit.m_imageHeaderSize + 4 + 512);
            qint32* ptr = xFrameOffsets.get();
            for (qint32 i = 0; i < xWdfUnit.m_directionCount; i++)
            {
                for (qint32 n = 0; n < xWdfUnit.m_frameCount; n++)
                {
                    xUnitStream >> ptr[(i * xWdfUnit.m_frameCount + n)];
                }
            }


            // 根据朝向,帧数读取纹理
            for (qint32 xDirectionIndex = 0; xDirectionIndex < xWdfUnit.m_directionCount; xDirectionIndex++)
            {
                for (qint32 xFrameIndex = 0; xFrameIndex < xWdfUnit.m_frameCount; xFrameIndex++)
                {
                    std::shared_ptr<quint32> xImageData(LAMBDA_AUTO_NEW_DELETE_ARRAY(quint32, xWdfUnit.m_width * xWdfUnit.m_height));
                    xWdfUnit.m_resProductDatas.append(xImageData);
                    quint32* lpImageData = xImageData.get();
                    memset(lpImageData, 0, sizeof(quint32) * xWdfUnit.m_width * xWdfUnit.m_height);

                    Boolean IsInterlacedgh = False;

                    qint32 xOffset = ptr[xDirectionIndex * xWdfUnit.m_frameCount + xFrameIndex];
                    if (xOffset != 0)
                    {
                        xUnitStream.device()->seek(xOffset + xWdfUnit.m_imageHeaderSize + 4);

                        xUnitStream >> textureInfo.hotX >> textureInfo.hotY >> textureInfo.width >> textureInfo.height;

                        std::shared_ptr<qint32> xLineOffsets(LAMBDA_AUTO_NEW_DELETE_ARRAY(qint32, textureInfo.height));
                        qint32* lineptr = xLineOffsets.get();
                        for (qint32 l = 0; l < textureInfo.height; l++) { xUnitStream >> lineptr[l]; }

                        if (textureInfo.width > 0 || textureInfo.height > 0)
                        {
                            xyParseSome(xUnitStream, lpImageData, textureInfo.width, xPalette, xOffset, lineptr, textureInfo.width, textureInfo.height, xWdfUnit.m_imageHeaderSize, IsInterlacedgh);
                        }
                    }

                    if (IsInterlacedgh)
                    {
                        for (int y = 0; y < xWdfUnit.m_height; y++)
                        {
                            if (((y % 2) == 0) && y < (xWdfUnit.m_height - 1))
                            {
                                void* lpDst = &(lpImageData[(y + 1) * xWdfUnit.m_width]);
                                void* lpSrc = &(lpImageData[(y)* xWdfUnit.m_width]);
                                memcpy(lpDst, lpSrc, xWdfUnit.m_width * sizeof(quint32));
                            }
                        }
                    }
                    xUnitStream.device()->seek(0);

                    std::shared_ptr<QImage> xImage(LAMBDA_AUTO_NEW_DELETE_P4(QImage,
                        (uchar*)lpImageData, xWdfUnit.m_width, xWdfUnit.m_height, QImage::Format::Format_ARGB32)
                    );
                    xWdfUnit.m_ProductImages.append(xImage);
                }
            }
        }

        imageVector.clear();

        QVectorIterator<std::shared_ptr<QImage>> it(xWdfUnit.m_ProductImages);
        while (it.hasNext())
        {
            imageVector.append(it.next().get());
        }
        return True;
    }
    catch (...) {}
    return False;
}

Boolean
pjResManager::pjGetMp3(quint64 unitKey, QBuffer* mp3Buffer)
{
    // 资源不存在
    if (m_hashReses.find(unitKey) == m_hashReses.end())
    {
        return False;
    }

    // 资源文件对应表不存在
    if (m_hashReskeyResFilename.find((quint32)(unitKey >> 32)) == m_hashReskeyResFilename.end()) { return False; }

    // 读取单元数据
    xyUnit& xWdfUnit = m_hashReses[unitKey];
    quint32& xLen = xWdfUnit.m_UnitFileInfo.m_Len;

    try
    {
        if (!xWdfUnit.m_resOriginalData)
        {
            QFile xFile(m_hashReskeyResFilename[(quint32)(unitKey >> 32)]);
            if (!xFile.open(QIODevice::ReadOnly))
            {
                qCritical(QString(u8"打开资源文件失败:%1").arg(m_hashReskeyResFilename[(quint32)(unitKey >> 32)]).toStdString().c_str());
                return False;
            }
            xFile.seek(xWdfUnit.m_UnitFileInfo.m_Addr);
            QDataStream xFileStream(&xFile);
            xFileStream.setByteOrder(QDataStream::LittleEndian);

            xWdfUnit.m_resOriginalData.reset(LAMBDA_AUTO_NEW_DELETE_ARRAY(char, xLen));
            if (xLen != xFileStream.readRawData(xWdfUnit.m_resOriginalData.get(), xLen))
            {
                qCritical(QString(u8"读取资源文件失败:%1").arg(m_hashReskeyResFilename[(quint32)(unitKey >> 32)]).toStdString().c_str());
                return False;
            }

            xWdfUnit.m_ByteArray = NEW QByteArray(xWdfUnit.m_resOriginalData.get(), xLen);
            mp3Buffer->setBuffer(xWdfUnit.m_ByteArray);
            return True;
        }
    }
    catch (...) {}
    return False;
}

// 加载资源文件
Boolean LoadFile(QString&& filename, quint32& filekey)
{
    return pj_GetResManager().pjLoadFile(std::forward<QString>(filename), filekey);
}

// 获取资源总数
quint32 GetUnitSum()
{
    return pj_GetResManager().pjGetUnitSum();
}

// 获取动画纹理数量(64位前32位代表朝向数量,后32位代表帧数)
Boolean GetWasTextureSum(quint64 unitKey, quint64 texSum, quint64 texSize)
{
    return pj_GetResManager().pjGetWasTextureSum(unitKey, texSum, texSize);
}

//// 加载动画列表
//Boolean GetWasTextures(xyTextureInfo* ptrTextureInfo, qint32& textureSum)
//{
//    return g_pjResManager.pjGetWasTextures(ptrTextureInfo, textureSum);
//}
