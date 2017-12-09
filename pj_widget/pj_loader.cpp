#include "Precompiled.h"
#include "pj_loader.h"

pjResManager g_pjResManager;


inline Boolean
xyReadFile(mstr filename, uint32_t filekey, std::map<uint64_t, xyUnit>& mapReses)
{
    try
    {
        std::shared_ptr<FILE> xFile(
            fopen(filename.c_str(), "rb"),
            FAST_LAMBDA_CALL(fclose)
        );

        if (xFile == nullptr) { return False; }

        LPBYTE m_MemoryDataOffset = nullptr;

        // 检查文件头标记
        uint32_t xFileHeadFlag = 0;
        READ_FILE_ASSIST(xFile.get(), xFileHeadFlag, "文件头标记");
        if (xFileHeadFlag != 0x57444650) { return False; }

        uint32_t xUnitCount;
        uint32_t xCatalogListAddr;

        // 读取文件头
        READ_FILE_ASSIST(xFile.get(), xUnitCount, "单元数量");
        READ_FILE_ASSIST(xFile.get(), xCatalogListAddr, "单元地址");

        fseek(xFile.get(), xCatalogListAddr, SEEK_SET);

        for (uint32_t i = 0; i < xUnitCount; i++)
        {
            xyUnit tempUnit;
            READ_FILE_ASSIST(xFile.get(), tempUnit.m_UnitFileInfo, "单元信息");
            uint64_t xKey = filekey;
            xKey <<= 32;
            xKey += tempUnit.m_UnitFileInfo.m_Key;
            mapReses[xKey] = tempUnit;
        }

        return True;
    }
    catch (...) {}
    return False;
}

inline void
xyParseSome(MemoryStream& xStream, uint32_t* lpTextureData, int32_t xTextureWidth,
    WPixels& xPalette, int32_t xFrameOffset, int32_t* xLineOffsets,
    uint32_t xFrameWidth, uint32_t xFrameHeight, uint16_t imageHeaderSize, Boolean& IsInterlacedgh)
{
    uint32_t xLimitWidth = xFrameWidth;
    uint32_t xLimitHeight = xFrameHeight;

    IsInterlacedgh = True;
    for (uint32_t xIndexY = 0; xIndexY < xFrameHeight; xIndexY++)
    {
        xStream.OutSeek(xLineOffsets[xIndexY] + xFrameOffset + imageHeaderSize + 4);
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
Boolean pjResManager::pjLoadFile(mstr filename, uint32_t filekey)
{
    auto xRet = xyReadFile(filename, filekey, m_mapReses);
    m_mapLoadedRes[filekey] = xRet;
    if (xRet) { m_mapReskey_ResFilename[filekey] = filename; }
    return xRet;
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
    std::shared_ptr<uint8_t> xTempdata(NEW uint8_t[xLen], FAST_LAMBDA_DELETE_ARRAY);

    try
    {
        std::shared_ptr<FILE> xFile(
            fopen(m_mapReskey_ResFilename[(uint32_t)(unitKey >> 32)].c_str(), "rb"), FAST_LAMBDA_CALL(fclose));

        if (xFile == nullptr) { return False; }

        fseek(xFile.get(), xWdfUnit.m_UnitFileInfo.m_Addr, SEEK_SET);

        if (xLen != (uint32_t)fread(xTempdata.get(), sizeof(uint8_t), xLen, xFile.get())) { return False; }

        MemoryStream xStream(xTempdata.get(), xLen);
        xStream.OutSeek(0);

        // 检查文件头标记
        WORD xFileHeadFlag;
        xStream >> xFileHeadFlag;
        if (xFileHeadFlag != 0x5053) { return 0; }

        WORD imageHeaderSize;
        WORD directionCount;
        WORD frameCount;
        WORD width;
        WORD height;

        xStream >> imageHeaderSize >> directionCount >> frameCount >> width >> height;

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
Boolean pjResManager::pjGetWasTextures(xyTextureInfo& textureInfo, std::vector<MemoryStream>& xListTexStream)
{
    uint64_t unitKey = textureInfo.resKey;

    // 资源不存在
    if (m_mapReses.find(unitKey) == m_mapReses.end()) { return False; }

    // 资源文件对应表不存在
    if (m_mapReskey_ResFilename.find((uint32_t)(unitKey >> 32)) == m_mapReskey_ResFilename.end()) { return False; }

    // 读取动画数据
    xyUnit& xWdfUnit = m_mapReses[unitKey];
    uint32_t& xLen = xWdfUnit.m_UnitFileInfo.m_Len;
    std::shared_ptr<uint8_t> xTempdata(NEW uint8_t[xLen], FAST_LAMBDA_DELETE_ARRAY);

    try
    {
        std::shared_ptr<FILE> xFile(
            fopen(m_mapReskey_ResFilename[(uint32_t)(unitKey >> 32)].c_str(), "rb"), FAST_LAMBDA_CALL(fclose));

        if (xFile == nullptr) { return False; }

        fseek(xFile.get(), xWdfUnit.m_UnitFileInfo.m_Addr, SEEK_SET);

        if (xLen != (uint32_t)fread(xTempdata.get(), sizeof(uint8_t), xLen, xFile.get())) { return False; }

        MemoryStream xStream(xTempdata.get(), xLen);
        xStream.OutSeek(0);

        // 检查文件头标记
        WORD xFileHeadFlag;
        xStream >> xFileHeadFlag;
        if (xFileHeadFlag != 0x5053) { return 0; }

        WORD imageHeaderSize;
        WORD directionCount;
        WORD frameCount;
        WORD width;
        WORD height;
        short hotX;
        short hotY;

        xStream >> imageHeaderSize >> directionCount >> frameCount >> width >> height >> hotX >> hotY;

        // 读取帧延迟信息(暂时不需要,先丢弃)
        int16_t xLen = (int16_t)(imageHeaderSize - 12);
        if (xLen > 0)
        {
            for (int32_t i = 0; i < xLen; i++)
            {
                uint8_t xDelays = 0;
                xStream >> xDelays;
            }
        }

        // 读取调色板
        WPixels xPalette = { 0 };
        xStream.OutSeek(imageHeaderSize + 4);
        xStream >> xPalette;

        // 读取帧偏移
        std::shared_ptr<int32_t> xFrameOffsets(NEW int32_t[directionCount * frameCount], FAST_LAMBDA_DELETE_ARRAY);
        xStream.OutSeek(imageHeaderSize + 4 + 512);
        int32_t* ptr = xFrameOffsets.get();
        for (int32_t i = 0; i < directionCount; i++)
        {
            for (int32_t n = 0; n < frameCount; n++)
            {
                xStream >> ptr[(i * frameCount + n)];
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
                    xStream.OutSeek(xOffset + imageHeaderSize + 4);
                    //int32_t xFrameWidth;
                    //int32_t xFrameHeight;

                    xStream >> textureInfo.hotX >> textureInfo.hotY >> textureInfo.width >> textureInfo.height;

                    std::shared_ptr<int32_t> xLineOffsets(NEW int32_t[textureInfo.height], FAST_LAMBDA_DELETE_ARRAY);
                    int32_t* lineptr = xLineOffsets.get();
                    for (int32_t l = 0; l < textureInfo.height; l++) { xStream >> lineptr[l]; }

                    if (textureInfo.width > 0 || textureInfo.height > 0)
                    {
                        xyParseSome(xStream, xImageData, textureInfo.width, xPalette, xOffset, lineptr, textureInfo.width, textureInfo.height, imageHeaderSize, IsInterlacedgh);
                    }
                }

                if (IsInterlacedgh)
                {
                    for (int y = 0; y < height; y++)
                    {
                        if (((y % 2) == 0) && y < (height - 1))
                        {
                            LPVOID lpDst = &(xImageData[(y + 1) * width]);
                            LPVOID lpSrc = &(xImageData[(y)* width]);
                            memcpy(lpDst, lpSrc, width * sizeof(uint32_t));
                        }
                    }
                }
                xStream.OutSeek(0);

                MemoryStream xTempStream((LPBYTE)xImageData, width* height * sizeof(DWORD));
                xListTexStream.push_back(xTempStream);
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
