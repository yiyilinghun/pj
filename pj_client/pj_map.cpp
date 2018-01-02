#include "Precompiled.h"
#include "pj_loader.h"
#include "pj_map.h"

inline std::shared_ptr<quint8> JpgHandler(quint8* buffer, qint32 xInSize, qint32& xOutSize, qint32& xUseSize)
{
    // JPEG���ݴ���ԭ��
    // 1������D8��D9�����ݵ���������
    // 2��ɾ����3��4���ֽ� FFA0
    // 3���޸�FFDA�ĳ���00 09 Ϊ 00 0C
    // 4����FFDA���ݵ�������00 3F 00
    // 5���滻FFDA��FF D9֮���FF����ΪFF 00
    qint32 TempNum = 0;                            // ��ʱ��������ʾ�Ѷ�ȡ�ĳ���
    std::shared_ptr<quint8> outBuffer(NEW quint8[xInSize * 2]);
    quint8* TempBuffer = outBuffer.get();
    memset(TempBuffer, 0, xInSize * 2);
    quint16 TempTimes = 0;                         // ��ʱ��������ʾѭ���Ĵ���
    qint32 Temp = 0;

    // ���Ѷ�ȡ���ݵĳ���С���ܳ���ʱ����
    while (TempNum < xInSize && *buffer++ == 0xFF)
    {
        *TempBuffer++ = 0xFF;
        TempNum++;
        switch (*buffer)
        {
            case 0xD8: {*TempBuffer++ = 0xD8; *buffer++; TempNum++; }break;
            case 0xA0: { *buffer++; TempBuffer--; TempNum++; }break;
            case 0xC0:
            {
                *TempBuffer++ = 0xC0; *buffer++; TempNum++;
                TempTimes = (quint16)((quint16)(buffer[0]) * 0x100 + (quint16)(buffer[1]));
                for (int i = 0; i < TempTimes; i++) {
                    *TempBuffer++ = *buffer++;
                    TempNum++;
                }
            }break;

            case 0xC4:
            {
                *TempBuffer++ = 0xC4; *buffer++; TempNum++;
                TempTimes = (quint16)((quint16)(buffer[0]) * 0x100 + (quint16)(buffer[1]));
                for (int i = 0; i < TempTimes; i++) { *TempBuffer++ = *buffer++; TempNum++; }
            }break;

            case 0xDB:
            {
                *TempBuffer++ = 0xDB; *buffer++; TempNum++;
                TempTimes = (quint16)((quint16)(buffer[0]) * 0x100 + (quint16)(buffer[1]));
                for (int i = 0; i < TempTimes; i++) { *TempBuffer++ = *buffer++; TempNum++; }
            }break;

            case 0xDA:
            {
                *TempBuffer++ = 0xDA; *TempBuffer++ = 0x00; *TempBuffer++ = 0x0C; *buffer++;
                TempNum++; TempTimes = (quint16)((quint16)(buffer[0]) * 0x100 + (quint16)(buffer[1])); *buffer++; TempNum++; *buffer++;
                for (int i = 2; i < TempTimes; i++) { *TempBuffer++ = *buffer++; TempNum++; }
                *TempBuffer++ = 0x00; *TempBuffer++ = 0x3F; *TempBuffer++ = 0x00;
                Temp += 1; // ����Ӧ����+3�ģ���Ϊǰ���0xFFA0û��-2����������ֻ+1��
                           // ѭ������0xFFDA��0xFFD9֮�����е�0xFF�滻Ϊ0xFF00
                for (; TempNum < xInSize - 2;)
                {
                    if (*buffer == 0xFF) { *TempBuffer++ = 0xFF; *TempBuffer++ = 0x00; *buffer++; TempNum++; Temp++; }
                    else { *TempBuffer++ = *buffer++; TempNum++; }
                }

                // ֱ��������д����0xFFD9����JpegͼƬ.
                Temp--; // �������һ���ֽڣ����Լ�ȥ��
                *TempBuffer--;
                *TempBuffer-- = 0xD9;
            }break;

            case 0xD9:
            {
                // �㷨���⣬���ﲻ�ᱻִ�У������һ����
                *TempBuffer++ = 0xD9; TempNum++;
            }break;

            default: {}break;
        }
    }
    Temp += xInSize;
    xOutSize = Temp;

    xUseSize = TempNum;
    return outBuffer;
}

QRectF pj_mapCell::boundingRect() const
{
    QRectF x = { 0,0,(qreal)MAP_BLOCK_WIDTH,(qreal)MAP_BLOCK_HEIGHT };
    auto p = this->pos();
    return x;
}

void pj_mapCell::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    do
    {
        if (!m_jpeg) { break; }
        if (!m_blockImage)
        {
            quint8* data = m_jpeg->m_Data.get();
            if (*((quint32*)data) != 0xC0FFD8FF && *((quint32*)data) != 0xE0FFD8FF)
            {
                qint32 xOutSize = 0;
                qint32 xUseSize = 0;
                std::shared_ptr<quint8> blockImageData = JpgHandler(data, m_jpeg->m_Size, xOutSize, xUseSize);
                QByteArray xArray((const char*)blockImageData.get(), xOutSize);
                m_blockImage.reset(NEW QImage());
                m_blockImage->loadFromData(xArray);
            }
            else
            {
                break;
            }
        }
        painter->drawImage(0, 0, *(m_blockImage.get()));
    } while (False);
}

pj_map::pj_map(QString&& file)
    : m_File(file)
{
    ;
}

//
//QVector<MapMask*> ReadMask(qint32 xMaskOffset)
//{
//    MsList<MapMask*> xRetList;
//    //::SetFilePointer(m_hFile, xMaskOffset, 0, FILE_BEGIN);
//    m_MapDataOffset = m_MapData + xMaskOffset;
//    if (m_MapHeaderFlag == MAP_M1_0_HEADER_FLAG)
//    {
//        MapMask* lpMask = NEW MapMask();
//        MapMask::MaskInfo& xMaskInfo = lpMask->m_MaskInfo;
//        //READ_FILE_ASSIST(m_hFile, xMaskInfo, "���ֵ�Ԫ��Ϣ");
//        READ_MEMORY_ASSIST(m_MapDataOffset, xMaskInfo, "���ֵ�Ԫ��Ϣ");
//
//        if (xMaskInfo.m_Width == 0 || xMaskInfo.m_Height == 0 || xMaskInfo.m_MaskSize == 0) { return xRetList; }
//
//        LPBYTE& lpMaskData = lpMask->m_MaskData;
//        lpMaskData = NEW quint8[xMaskInfo.m_MaskSize];
//        ARRAY_READ_MEMORY_ASSIST(m_MapDataOffset, lpMaskData, xMaskInfo.m_MaskSize, "��������");
//        xRetList.Add(lpMask);
//    }
//    else if (m_MapHeaderFlag == MAP_M3_0_HEADER_FLAG)
//    {
//        MapMask* lpMask = NEW MapMask();
//        MapMask::MaskInfo& xMaskInfo = lpMask->m_MaskInfo;
//        //READ_FILE_ASSIST(m_hFile, xMaskInfo, "���ֵ�Ԫ��Ϣ");
//        READ_MEMORY_ASSIST(m_MapDataOffset, xMaskInfo, "���ֵ�Ԫ��Ϣ");
//        for (qint32 i = 0; i < xMaskInfo.m_MaskSize; i++)
//        {
//            //xMaskInfo.m_MaskSize
//            //if (xMaskInfo.m_Width == 0 || xMaskInfo.m_Height == 0 || xMaskInfo.m_MaskSize == 0) { return nullptr; }
//
//            LPBYTE& lpMaskData = lpMask->m_MaskData;
//            lpMaskData = NEW quint8[xMaskInfo.m_MaskSize];
//            ARRAY_READ_MEMORY_ASSIST(m_MapDataOffset, lpMaskData, xMaskInfo.m_MaskSize, "��������");
//            xRetList.Add(lpMask);
//        }
//    }
//
//    return xRetList;
//}
//

Boolean pj_map::ReadBlockUnit(QDataStream& xStream, pj_mapCell* mapCell)
{
    BlockUnitInfo xBlockUnitInfo;
    xBlockUnitInfo.m_Flag = 0;
    xStream >> xBlockUnitInfo;

    switch (xBlockUnitInfo.m_Flag)
    {
        case MAP_IMAG_FLAG:
        {
            if (mapCell->m_imag) { qDebug(u8"xMapBlock->m_imag�Ѿ�����"); }
            mapCell->m_imag.reset(NEW BlockUnitData());
            xStream >> ReadBytesAssist(mapCell->m_cell->m_Data, xBlockUnitInfo.m_Size);
            mapCell->m_imag->m_Flag = xBlockUnitInfo.m_Flag;
            mapCell->m_imag->m_Size = xBlockUnitInfo.m_Size;
        }break;

        case MAP_MSK2_FLAG:
        {
            if (mapCell->m_msk2) { qDebug(u8"xMapBlock->m_msk2�Ѿ�����"); }
            mapCell->m_msk2.reset(NEW BlockUnitData());
            xStream >> ReadBytesAssist(mapCell->m_msk2->m_Data, xBlockUnitInfo.m_Size);
            mapCell->m_msk2->m_Flag = xBlockUnitInfo.m_Flag;
            mapCell->m_msk2->m_Size = xBlockUnitInfo.m_Size;
        }break;

        case MAP_MASK_FLAG:
        {
            if (m_MapHeaderFlag == MAP_M1_0_HEADER_FLAG)
            {
                if (mapCell->m_mask.size() > 0) { qDebug("xMapBlock->m_mask�Ѿ�����"); }
                std::shared_ptr<BlockUnitData> xMask(NEW BlockUnitData());
                LPBYTE xData = NEW BYTE[xBlockUnitInfo.m_Size];
                xStream >> ReadBytesAssist(mapCell->m_cell->m_Data, xBlockUnitInfo.m_Size);
                mapCell->m_cell->m_Flag = xBlockUnitInfo.m_Flag;
                mapCell->m_cell->m_Size = xBlockUnitInfo.m_Size;
                mapCell->m_mask.append(xMask);
            }
            //if (m_MapHeaderFlag == MAP_M3_0_HEADER_FLAG)
            //{
            //    if (mapCell->m_mask.size() > 0) { qDebug("xMapBlock->m_mask�Ѿ�����"); }

            //    for (Int32 i = 0; i < xBlockUnitInfo.m_Size; i++)
            //    {
            //        BlockUnitData* xMask = NEW BlockUnitData();
            //        LPBYTE xData = NEW BYTE[4];
            //        ARRAY_READ_MEMORY_ASSIST(m_MapDataOffset, xData, 4, "��������");
            //        xMask->m_Flag = xBlockUnitInfo.m_Flag;
            //        xMask->m_Size = xBlockUnitInfo.m_Size;
            //        xMask->m_Data = xData;
            //        xMapBlock->m_mask.Add(xMask);
            //    }
            //}
        }break;

        case MAP_GEPJ_FLAG:
        {
            if (mapCell->m_jpeg) { qDebug(u8"xMapBlock->m_jpeg�Ѿ�����"); }
            mapCell->m_jpeg.reset(NEW BlockUnitData());
            xStream >> ReadBytesAssist(mapCell->m_jpeg->m_Data, xBlockUnitInfo.m_Size);
            mapCell->m_jpeg->m_Flag = xBlockUnitInfo.m_Flag;
            mapCell->m_jpeg->m_Size = xBlockUnitInfo.m_Size;
        }break;

        case MAP_BLOK_FLAG:
        {
            if (mapCell->m_blok) { qDebug(u8"xMapBlock->m_blok�Ѿ�����"); }
            mapCell->m_blok.reset(NEW BlockUnitData());
            xStream >> ReadBytesAssist(mapCell->m_blok->m_Data, xBlockUnitInfo.m_Size);
            mapCell->m_blok->m_Flag = xBlockUnitInfo.m_Flag;
            mapCell->m_blok->m_Size = xBlockUnitInfo.m_Size;
        }break;

        case MAP_CELL_FLAG:
        {
            if (mapCell->m_cell) { qDebug(u8"xMapBlock->m_cell�Ѿ�����"); }
            mapCell->m_cell.reset(NEW BlockUnitData());
            xStream >> ReadBytesAssist(mapCell->m_cell->m_Data, xBlockUnitInfo.m_Size);
            mapCell->m_cell->m_Flag = xBlockUnitInfo.m_Flag;
            mapCell->m_cell->m_Size = xBlockUnitInfo.m_Size;
        }break;

        case MAP_BRIG_FLAG:
        {
            if (mapCell->m_brig) { qDebug(u8"xMapBlock->m_brig�Ѿ�����"); }
            mapCell->m_brig.reset(NEW BlockUnitData());
            xStream >> ReadBytesAssist(mapCell->m_brig->m_Data, xBlockUnitInfo.m_Size);
            mapCell->m_brig->m_Flag = xBlockUnitInfo.m_Flag;
            mapCell->m_brig->m_Size = xBlockUnitInfo.m_Size;
        }break;

        case MAP_LIGT_FLAG:
        {
            if (mapCell->m_ligt) { qDebug(u8"xMapBlock->m_ligt�Ѿ�����"); }
            mapCell->m_ligt.reset(NEW BlockUnitData());
            xStream >> ReadBytesAssist(mapCell->m_ligt->m_Data, xBlockUnitInfo.m_Size);
            mapCell->m_ligt->m_Flag = xBlockUnitInfo.m_Flag;
            mapCell->m_ligt->m_Size = xBlockUnitInfo.m_Size;
        }break;

        case MAP_DNE__FLAG:
        default: { return False; }break;
    }
    return True;
}


Boolean pj_map::ReadBlockUnitCellOnly(QDataStream& xStream, pj_mapCell* mapCell)
{
    BlockUnitInfo xBlockUnitInfo;
    xBlockUnitInfo.m_Flag = 0;
    xStream >> xBlockUnitInfo;

    switch (xBlockUnitInfo.m_Flag)
    {
        case MAP_LIGT_FLAG:
        case MAP_BRIG_FLAG:
        case MAP_BLOK_FLAG:
        case MAP_IMAG_FLAG:
        case MAP_MSK2_FLAG:
        case MAP_GEPJ_FLAG: { xStream.device()->seek(xStream.device()->pos() + xBlockUnitInfo.m_Size); }break;

        case MAP_MASK_FLAG:
        {
            if (m_MapHeaderFlag == MAP_M1_0_HEADER_FLAG) { xStream.device()->seek(xStream.device()->pos() + xBlockUnitInfo.m_Size); }
            if (m_MapHeaderFlag == MAP_M3_0_HEADER_FLAG) { xStream.device()->seek(xStream.device()->pos() + xBlockUnitInfo.m_Size); }
        }break;

        case MAP_CELL_FLAG:
        {
            if (mapCell->m_cell) { qDebug(u8"xMapBlock->m_cell�Ѿ�����"); }
            mapCell->m_cell.reset(NEW BlockUnitData());
            xStream >> ReadBytesAssist(mapCell->m_cell->m_Data, xBlockUnitInfo.m_Size);
            mapCell->m_cell->m_Flag = xBlockUnitInfo.m_Flag;
            mapCell->m_cell->m_Size = xBlockUnitInfo.m_Size;
            return False;
        }break;

        case MAP_DNE__FLAG:
        default: { return False; }break;
    }
    return True;
}

pj_mapCell* pj_map::readCellData(quint32 cellAddr)
{
    try
    {
        QDataStream xStream(&m_File);
        xStream.setByteOrder(QDataStream::LittleEndian);
        m_File.seek(cellAddr);

        pj_mapCell* mapCell = NEW pj_mapCell(this, m_MapHeaderFlag);
        if (m_MapHeaderFlag == MAP_M1_0_HEADER_FLAG)
        {
            xStream >> mapCell->m_UnitCount;
            xStream >> ReadBytesAssist(mapCell->m_UnitAddr, sizeof(quint32) * mapCell->m_UnitCount);
        }

        while (ReadBlockUnit(xStream, mapCell))
        {
            ;
        }
        return mapCell;
    }
    catch (...) { ; }
    return nullptr;
}

Boolean pj_map::load()
{
    if (!m_File.open(QIODevice::ReadOnly))
    {
        qCritical(QString(u8"�򿪵�ͼ�ļ�ʧ��:%1").arg(m_File.fileName()).toStdString().c_str());
        return False;
    }

    QDataStream xStream(&m_File);
    xStream.setByteOrder(QDataStream::LittleEndian);
    m_File.seek(0);

    xStream >> m_MapHeaderFlag;
    if (MAP_M1_0_HEADER_FLAG == m_MapHeaderFlag)
    {
        xStream >> m_MapHeader_1_0;

        // ����ֿ�����
        m_MapBlockColNum = GetMapHeader_Width() / MAP_BLOCK_WIDTH; if (GetMapHeader_Width() % MAP_BLOCK_WIDTH != 0) { m_MapBlockColNum++; }
        m_MapBlockRowNum = GetMapHeader_Height() / MAP_BLOCK_HEIGHT; if (GetMapHeader_Height() % MAP_BLOCK_HEIGHT != 0) { m_MapBlockRowNum++; }

        // ����ͼƬ�ߴ�
        m_MapBmpWidth = m_MapBlockColNum * MAP_BLOCK_WIDTH;
        m_MapBmpHeight = m_MapBlockRowNum * MAP_BLOCK_HEIGHT;
        this->setSceneRect(0, 0, m_MapBmpWidth, m_MapBmpHeight);

        // ��ȡ���ַ
        xStream >> ReadBytesAssist(m_ArrayBlockOffset, sizeof(quint32) * m_MapBlockRowNum * m_MapBlockColNum);

        // ��ȡ��������ͷ
        xStream >> m_MaskHead;

        // ��ȡ���ֵ�ַ
        xStream >> ReadBytesAssist(m_ArrayMaskOffset, sizeof(quint32) * m_MaskHead.m_MaskNum);

        // �����ϰ������ڴ�ռ�
        m_BarrierWidth = GetMapHeader_Width() / MAP_BARRIER_LATTICE_PIXEL_WIDTH_SIZE;
        m_BarrierHeight = GetMapHeader_Height() / MAP_BARRIER_LATTICE_PIXEL_HEIGHT_SIZE;
        m_BarrierData.reset(NEW quint8[m_MapBlockRowNum * m_MapBlockColNum * MAP_BARRIER_WIDTH * MAP_BARRIER_HEIGHT]);
        m_BarrierData_ = m_BarrierData.get();
        memset(m_BarrierData_, 1, m_MapBlockRowNum * m_MapBlockColNum * MAP_BARRIER_WIDTH * MAP_BARRIER_HEIGHT);

        for (quint32 xIndex = 0; xIndex < m_MapBlockColNum * m_MapBlockRowNum; xIndex++)
        {
            pj_mapCell* mapCell = readCellData(m_ArrayBlockOffset.get()[xIndex]);
            if (mapCell)
            {
                this->addItem(mapCell);
                qint32 x = xIndex % m_MapBlockColNum * MAP_BLOCK_WIDTH;
                qint32 y = xIndex / m_MapBlockColNum * MAP_BLOCK_HEIGHT;
                mapCell->setPos(x, y);
                qDebug(QString("x=%1,y=%2").arg(x).arg(y).toStdString().c_str());
                _mapCellVector.append(mapCell);
            }
        }

        for (int i = 0; i < m_MaskHead.m_MaskNum; i++)
        {
            //MsList<MapMask*> lpMask = ReadMask(m_ArrayMaskOffset[i]);
            //NAME_FOREACH(xMaskEnum, lpMask)
            //{
            //    MapMask* xMask = xMaskEnum.GetValue();
            //    m_List_MapMasks.Add(xMask);
            //    LPBYTE lpData = DecompressJpg(xMask->m_MaskData, xMask->m_MaskInfo.m_Width, xMask->m_MaskInfo.m_Height, xMask->m_MaskDataSize);
            //    SAFE_DELETE_ARRAY(xMask->m_MaskData);
            //    xMask->m_MaskData = lpData;
            //    this->GetIndexByRect(xMask->m_SetBlockIndex, xMask->m_MaskInfo.m_StartX, xMask->m_MaskInfo.m_StartY, xMask->m_MaskInfo.m_Width, xMask->m_MaskInfo.m_Height);
            //    //qint32 xIndex = this->GetIndexByPos(lpMask->m_MaskInfo.m_StartX, lpMask->m_MaskInfo.m_StartY);
            //    FAST_FOREACH(xMask->m_SetBlockIndex)
            //    {
            //        qint32 xIndex = xEnumValue;
            //        if (!m_Dict_MapMasks.ContainsKey(xIndex))
            //        {
            //            m_Dict_MapMasks.Add(xIndex, ListMapMask());
            //        }
            //        m_Dict_MapMasks[xIndex].m_Masks.Add(xMask);
            //    }
            //}
        }
        return True;
    }
    return False;
}

