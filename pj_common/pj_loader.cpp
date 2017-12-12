#include "Precompiled.h"
#include "pj_loader.h"

pjResManager g_pjResManager;

inline Boolean
xyReadFile(QString filename, uint32_t filekey, std::map<uint64_t, xyUnit>& mapReses)
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

        uint32_t xFileHeadFlag = 0;
        xStream >> xFileHeadFlag;
        qDebug(QString(u8"读取文件头标记:%1").arg(filename).toStdString().c_str());
        if (xFileHeadFlag != 0x57444650)
        {
            qCritical(QString(u8"xFileHeadFlag != 0x57444650:%1").arg(filename).toStdString().c_str());
            return False;
        }

        uint32_t xUnitCount;
        uint32_t xCatalogListAddr;

        xStream >> xUnitCount;
        qDebug(QString(u8"读取单元数量:%1").arg(filename).toStdString().c_str());

        xStream >> xCatalogListAddr;
        qDebug(QString(u8"读取单元地址:%1").arg(filename).toStdString().c_str());

        xFile.seek(xCatalogListAddr);

        for (uint32_t i = 0; i < xUnitCount; i++)
        {
            xyUnit tempUnit;
            xStream >> tempUnit.m_UnitFileInfo;
            qDebug(QString(u8"读取单元信息:%1(%2)").arg(filename).arg(xUnitCount).toStdString().c_str());
            uint64_t xKey = filekey;
            xKey <<= 32;
            xKey += tempUnit.m_UnitFileInfo.m_Key;
            mapReses[xKey] = tempUnit;
        }

        xFile.close();
        return True;
    }
    catch (...) {}
    return False;
}

inline void
xyParseSome(QDataStream& xStream, uint32_t* lpTextureData, int32_t xTextureWidth,
    WPixels& xPalette, int32_t xFrameOffset, int32_t* xLineOffsets,
    uint32_t xFrameWidth, uint32_t xFrameHeight, uint16_t imageHeaderSize, Boolean& IsInterlacedgh)
{
    //QDataStream xStream(&xBuffer);
    uint32_t xLimitWidth = xFrameWidth;
    uint32_t xLimitHeight = xFrameHeight;

    IsInterlacedgh = True;
    for (uint32_t xIndexY = 0; xIndexY < xFrameHeight; xIndexY++)
    {
        xStream.device()->seek(xLineOffsets[xIndexY] + xFrameOffset + imageHeaderSize + 4);
        for (uint32_t xIndexX = 0; xIndexX < xFrameWidth;)
        {
            uint8_t xTemp;
            xStream >> xTemp;
            uint32_t xPixelTemp = (uint32_t)xTemp;

            // 象素行结束
            if (xPixelTemp == 0) { break; }

            switch (xPixelTemp & 0xC0)
            {
                case 0:
                {
                    if (xIndexY % 2) { IsInterlacedgh = False; }

                    if (xPixelTemp & 0x20)
                    {
                        uint32_t i = (uint32_t)(xStream >> xTemp, xTemp);
                        uint32_t x = xIndexX;
                        uint32_t y = xIndexY;
                        uint32_t a = (xPixelTemp & 0x1F);
                        if (x >= 0 && x < xLimitWidth && y >= 0 && y < xLimitHeight)
                        {
                            if (a) { a = (a << 3) - 7; lpTextureData[xTextureWidth * y + x] = WAS_MAKE_ARGB(xPalette.m_Palette[i].m_Color, a); }
                            xIndexX++;
                        }
                    }
                    else if (xPixelTemp)
                    {
                        uint32_t c = xPixelTemp & 0x1F;
                        uint32_t a = (uint32_t)(xStream >> xTemp, xTemp);
                        uint32_t i = (uint32_t)(xStream >> xTemp, xTemp);
                        if (a) { a = (a << 3) - 7; }
                        for (uint32_t xIndex = 0; xIndex < c; xIndex++)
                        {
                            uint32_t x = xIndexX;
                            uint32_t y = xIndexY;
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

                    uint32_t c = xPixelTemp & 0x3F;
                    for (uint32_t xIndex = 0; xIndex < c; xIndex++)
                    {
                        uint32_t i = (uint32_t)(xStream >> xTemp, xTemp);
                        uint32_t x = xIndexX;
                        uint32_t y = xIndexY;
                        if (x >= 0 && x < xLimitWidth && y >= 0 && y < xLimitHeight)
                        {
                            lpTextureData[xTextureWidth * y + x] = WAS_MAKE_ARGB(xPalette.m_Palette[i].m_Color, 0xFF);
                            xIndexX++;
                        }
                    }
                }break;

                case 0x80:
                {
                    if (xIndexY % 2) { IsInterlacedgh = False; }

                    uint32_t c = xPixelTemp & 0x3F;
                    uint32_t i = (uint32_t)(xStream >> xTemp, xTemp);
                    for (uint32_t xIndex = 0; xIndex < c; xIndex++)
                    {
                        uint32_t x = xIndexX;
                        uint32_t y = xIndexY;
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
//xySetTexturePixels(LPVOID hTextureHandle, uint32_t* lpPixels, int32_t xWidth, int32_t xHeight)
//{
//    int32_t xTextureRowPitch;
//    LPBYTE xTextureDataPtr = (LPBYTE)g_CurrentAPI->BeginModifyTexture(hTextureHandle, xWidth, xHeight, &xTextureRowPitch);
//    if (!xTextureDataPtr) { return False; }
//
//    LPBYTE xDst = xTextureDataPtr;
//    if (g_Graphics->GetRenderer() == kUnityGfxRendererD3D9)
//    {
//        for (int32_t y = 0; y < xHeight; y++)
//        {
//            LPBYTE xPtr = xDst;
//            for (int32_t x = 0; x < xWidth; x++)
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
//        for (int32_t y = 0; y < xHeight; y++)
//        {
//            LPBYTE xPtr = xDst;
//            for (int32_t x = 0; x < xWidth; x++)
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
Boolean pjResManager::pjLoadFile(QString filename, uint32_t filekey)
{
    if (m_mapLoadedRes.find(filekey) != m_mapLoadedRes.end())
    {
        return True;
    }
    else
    {
        auto xRet = xyReadFile(filename, filekey, m_mapReses);
        m_mapLoadedRes[filekey] = xRet;
        if (xRet) { m_mapReskey_ResFilename[filekey] = filename; }
        return xRet;
    }
}

// 获取资源总数
uint32_t pjResManager::pjGetUnitSum() { return (uint32_t)m_mapReses.size(); }


// 获取动画纹理数量(64位前32位代表朝向数量,后32位代表帧数)
Boolean pjResManager::pjGetWasTextureSum(uint64_t unitKey, uint64_t texSum, uint64_t texSize)
{
    // 资源不存在
    if (m_mapReses.find(unitKey) == m_mapReses.end()) { return 0; }

    // 资源文件对应表不存在
    if (m_mapReskey_ResFilename.find((uint32_t)(unitKey >> 32)) == m_mapReskey_ResFilename.end()) { return 0; }

    // 读取动画数据
    xyUnit& xWdfUnit = m_mapReses[unitKey];
    uint32_t& xLen = xWdfUnit.m_UnitFileInfo.m_Len;
    try
    {
        QFile xFile(m_mapReskey_ResFilename[(uint32_t)(unitKey >> 32)]);
        //std::shared_ptr<FILE> xFile(
        //    fopen(m_mapReskey_ResFilename[(uint32_t)(unitKey >> 32)].c_str(), "rb"), FAST_LAMBDA_CALL(fclose));
        if (!xFile.open(QIODevice::ReadOnly))
        {
            qCritical(QString(u8"打开资源文件失败:%1").arg(m_mapReskey_ResFilename[(uint32_t)(unitKey >> 32)]).toStdString().c_str());
            return False;
        }
        QDataStream xFileStream(&xFile);
        xFileStream.setByteOrder(QDataStream::LittleEndian);

        //if (xFile == nullptr) { return False; }

        xFile.seek(xWdfUnit.m_UnitFileInfo.m_Addr);
        //fseek(xFile.get(), xWdfUnit.m_UnitFileInfo.m_Addr, SEEK_SET);

        std::shared_ptr<char> xTempdata(NEW char[xLen], FAST_LAMBDA_DELETE_ARRAY);
        if (xLen != xFileStream.readRawData(xTempdata.get(), xLen))
        {
            qCritical(QString(u8"读取资源文件失败:%1").arg(m_mapReskey_ResFilename[(uint32_t)(unitKey >> 32)]).toStdString().c_str());
            return False;
        }
        //if (xLen != (uint32_t)fread(xTempdata.get(), sizeof(uint8_t), xLen, xFile.get())) { return False; }
        //MemoryStream xStream(xTempdata.get(), xLen);
        //xStream.OutSeek(0);
        QBuffer xBuffer;
        xBuffer.setData(xTempdata.get(), xLen);
        QDataStream xUnitStream(&xBuffer);
        xUnitStream.setByteOrder(QDataStream::LittleEndian);

        // 检查文件头标记
        uint16_t xFileHeadFlag;
        xUnitStream >> xFileHeadFlag;
        if (xFileHeadFlag != 0x5053)
        {
            qCritical(QString(u8"读取资源文件失败:%1").arg(m_mapReskey_ResFilename[(uint32_t)(unitKey >> 32)]).toStdString().c_str());
            return False;
        }

        uint16_t imageHeaderSize;
        uint16_t directionCount;
        uint16_t frameCount;
        uint16_t width;
        uint16_t height;

        xUnitStream >> imageHeaderSize >> directionCount >> frameCount >> width >> height;

        texSum = (((uint64_t)directionCount) << 32) + frameCount;
        texSize = (((uint64_t)width) << 32) + height;
        return True;
    }
    catch (...) {}
    return False;
}

//// 加载动画列表
//Boolean pjResManager::pjGetWasTextures(xyTextureInfo* ptrTextureInfo, int32_t& textureSum)
//{
//    for (int32_t i = 0; i < textureSum; i++)
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
Boolean pjResManager::pjGetWasTextures(xyTextureInfo& textureInfo, std::vector<QBuffer*>& xListTexStream)
{
    uint64_t unitKey = textureInfo.resKey;

    // 资源不存在
    if (m_mapReses.find(unitKey) == m_mapReses.end()) { return False; }

    // 资源文件对应表不存在
    if (m_mapReskey_ResFilename.find((uint32_t)(unitKey >> 32)) == m_mapReskey_ResFilename.end()) { return False; }

    // 读取动画数据
    xyUnit& xWdfUnit = m_mapReses[unitKey];
    uint32_t& xLen = xWdfUnit.m_UnitFileInfo.m_Len;

    try
    {
        QFile xFile(m_mapReskey_ResFilename[(uint32_t)(unitKey >> 32)]);
        if (!xFile.open(QIODevice::ReadOnly))
        {
            qCritical(QString(u8"打开资源文件失败:%1").arg(m_mapReskey_ResFilename[(uint32_t)(unitKey >> 32)]).toStdString().c_str());
            return False;
        }
        //std::shared_ptr<FILE> xFile(
        //    fopen(m_mapReskey_ResFilename[(uint32_t)(unitKey >> 32)].c_str(), "rb"), FAST_LAMBDA_CALL(fclose));
        //if (xFile == nullptr) { return False; }

        xFile.seek(xWdfUnit.m_UnitFileInfo.m_Addr);
        //fseek(xFile.get(), xWdfUnit.m_UnitFileInfo.m_Addr, SEEK_SET);

        QDataStream xFileStream(&xFile);
        xFileStream.setByteOrder(QDataStream::LittleEndian);

        std::shared_ptr<char> xTempdata(NEW char[xLen], FAST_LAMBDA_DELETE_ARRAY);
        if (xLen != xFileStream.readRawData(xTempdata.get(), xLen))
        {
            qCritical(QString(u8"读取资源文件失败:%1").arg(m_mapReskey_ResFilename[(uint32_t)(unitKey >> 32)]).toStdString().c_str());
            return False;
        }

        QByteArray xByteArray(xTempdata.get(), xLen);
        QDataStream xUnitStream(&xByteArray, QIODevice::ReadOnly);
        xUnitStream.setByteOrder(QDataStream::LittleEndian);
        xUnitStream.device()->seek(0);

        if (xUnitStream.atEnd())
        {        // 检查文件头标记
            uint16_t xFileHeadFlag;
            xUnitStream >> xFileHeadFlag;
            if (xFileHeadFlag != 0x5053) { return 0; }
        }
        else
        {
            // 检查文件头标记
            uint16_t xFileHeadFlag;
            xUnitStream >> xFileHeadFlag;
            if (xFileHeadFlag != 0x5053) { return 0; }
        }

        //// 检查文件头标记
        //uint16_t xFileHeadFlag;
        //xUnitStream >> xFileHeadFlag;
        //if (xFileHeadFlag != 0x5053) { return 0; }

        uint16_t imageHeaderSize;
        uint16_t directionCount;
        uint16_t frameCount;
        uint16_t width;
        uint16_t height;
        short hotX;
        short hotY;
        xUnitStream >> imageHeaderSize >> directionCount >> frameCount >> width >> height >> hotX >> hotY;

        // 读取帧延迟信息(暂时不需要,先丢弃)
        int16_t xLen = (int16_t)(imageHeaderSize - 12);
        if (xLen > 0)
        {
            for (int32_t i = 0; i < xLen; i++)
            {
                uint8_t xDelays = 0;
                xUnitStream >> xDelays;
            }
        }

        // 读取调色板
        WPixels xPalette = { 0 };
        xUnitStream.device()->seek(imageHeaderSize + 4);
        //xStream.OutSeek(imageHeaderSize + 4);
        xUnitStream >> xPalette;

        // 读取帧偏移
        std::shared_ptr<int32_t> xFrameOffsets(NEW int32_t[directionCount * frameCount], FAST_LAMBDA_DELETE_ARRAY);
        xUnitStream.device()->seek(imageHeaderSize + 4 + 512);
        //xStream.OutSeek(imageHeaderSize + 4 + 512);
        int32_t* ptr = xFrameOffsets.get();
        for (int32_t i = 0; i < directionCount; i++)
        {
            for (int32_t n = 0; n < frameCount; n++)
            {
                xUnitStream >> ptr[(i * frameCount + n)];
            }
        }

        // 根据朝向,帧数读取纹理
        for (int32_t xDirectionIndex = 0; xDirectionIndex < directionCount; xDirectionIndex++)
        {
            for (int32_t xFrameIndex = 0; xFrameIndex < frameCount; xFrameIndex++)
            {
                uint32_t* xImageData = NEW uint32_t[width * height];
                Boolean IsInterlacedgh = False;

                int32_t xOffset = ptr[xDirectionIndex * frameCount + xFrameIndex];
                if (xOffset != 0)
                {
                    xUnitStream.device()->seek(xOffset + imageHeaderSize + 4);
                    //xStream.OutSeek(xOffset + imageHeaderSize + 4);
                    //int32_t xFrameWidth;
                    //int32_t xFrameHeight;

                    xUnitStream >> textureInfo.hotX >> textureInfo.hotY >> textureInfo.width >> textureInfo.height;

                    std::shared_ptr<int32_t> xLineOffsets(NEW int32_t[textureInfo.height], FAST_LAMBDA_DELETE_ARRAY);
                    int32_t* lineptr = xLineOffsets.get();
                    for (int32_t l = 0; l < textureInfo.height; l++) { xUnitStream >> lineptr[l]; }

                    if (textureInfo.width > 0 || textureInfo.height > 0)
                    {
                        xyParseSome(xUnitStream, xImageData, textureInfo.width, xPalette, xOffset, lineptr, textureInfo.width, textureInfo.height, imageHeaderSize, IsInterlacedgh);
                    }
                }

                if (IsInterlacedgh)
                {
                    for (int y = 0; y < height; y++)
                    {
                        if (((y % 2) == 0) && y < (height - 1))
                        {
                            void* lpDst = &(xImageData[(y + 1) * width]);
                            void* lpSrc = &(xImageData[(y)* width]);
                            memcpy(lpDst, lpSrc, width * sizeof(uint32_t));
                        }
                    }
                }
                //xStream.OutSeek(0);
                xUnitStream.device()->seek(0);

                //MemoryStream xTempStream((LPBYTE)xImageData, width* height * sizeof(DWORD));
                QBuffer* xTarBuffer = NEW QBuffer();
                xTarBuffer->setData((const char*)xImageData, width* height * sizeof(uint32_t));
                xListTexStream.push_back(xTarBuffer);
                //xySetTexturePixels(textureInfo.textureHandle, xImageData, width, height);
            }
        }

        return True;
    }
    catch (...) {}
    return False;
}




// 加载资源文件
Boolean LoadFile(const char* filename, uint32_t filekey)
{
    return g_pjResManager.pjLoadFile(filename, filekey);
}

// 获取资源总数
uint32_t GetUnitSum()
{
    return g_pjResManager.pjGetUnitSum();
}

// 获取动画纹理数量(64位前32位代表朝向数量,后32位代表帧数)
Boolean GetWasTextureSum(uint64_t unitKey, uint64_t texSum, uint64_t texSize)
{
    return g_pjResManager.pjGetWasTextureSum(unitKey, texSum, texSize);
}

//// 加载动画列表
//Boolean GetWasTextures(xyTextureInfo* ptrTextureInfo, int32_t& textureSum)
//{
//    return g_pjResManager.pjGetWasTextures(ptrTextureInfo, textureSum);
//}
