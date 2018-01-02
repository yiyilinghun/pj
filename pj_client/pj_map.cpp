#include "Precompiled.h"
#include "pj_loader.h"
#include "pj_map.h"

QRectF pj_mapCell::boundingRect() const
{
    //qDebug(QString("%1,%2,%3,%4").arg(0).arg(0).arg(m_xyUnit->m_xyTextureInfo.width).arg(m_xyUnit->m_xyTextureInfo.height).toStdString().c_str());
    //return QRectF{ this->pos().x(),this->pos().y(),(qreal)m_xyUnit->m_xyTextureInfo.width ,(qreal)m_xyUnit->m_xyTextureInfo.height };
    //return QRectF{ 0,0,(qreal)m_xyUnit->m_xyTextureInfo.width ,(qreal)m_xyUnit->m_xyTextureInfo.height };
    return QRectF{ 0,0,0,0 };
}

void pj_mapCell::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    //hotImage& _hotImage = m_xyUnit->m_ProductImages[_wasaniAssist.m_indexAni % m_xyUnit->m_ProductImages.size()];
    //painter->drawImage(_hotImage.qPoint, *_hotImage.qImage.get());
}



//qint32 pjWasaniAssist::indexAni() const {
//    return m_indexAni;
//}
//void pjWasaniAssist::setIndexAni(const qint32 &v) {
//    if (v != m_indexAni)
//    {
//        m_indexAni = v;
//        //m_pj_wasani->update();
//    }
//}

pj_map::pj_map()
//:_wasaniAssist(this)
{
    //quint32 file_key = 0;
    //if (!pj_GetResManager().pjLoadFile(std::forward<QString>(file), file_key))
    //{
    //    return;
    //}

    //quint64 tempKey = (((quint64)file_key) << 32) + key;

    //if (!pj_GetResManager().pjGetWasTextures(tempKey, m_xyUnit))
    //{
    //    return;
    //}

    //this->setZValue(0.0000);
}


Boolean pj_map::load(QString&& file)
{
    QFile xFile(file);
    if (!xFile.open(QIODevice::ReadOnly))
    {
        qCritical(QString(u8"打开地图文件失败:%1").arg(file).toStdString().c_str());
        return False;
    }

    QDataStream xStream(&xFile);
    xStream.setByteOrder(QDataStream::LittleEndian);
    xFile.seek(0);

    xStream >> m_MapHeaderFlag;
    if (MAP_M1_0_HEADER_FLAG == m_MapHeaderFlag)
    {
        xStream >> m_MapHeader_1_0;

        // 计算分块数量
        m_MapBlockColNum = GetMapHeader_Width() / MAP_BLOCK_WIDTH; if (GetMapHeader_Width() % MAP_BLOCK_WIDTH != 0) { m_MapBlockColNum++; }
        m_MapBlockRowNum = GetMapHeader_Height() / MAP_BLOCK_HEIGHT; if (GetMapHeader_Height() % MAP_BLOCK_HEIGHT != 0) { m_MapBlockRowNum++; }

        // 计算图片尺寸
        m_MapBmpWidth = m_MapBlockColNum * MAP_BLOCK_WIDTH;
        m_MapBmpHeight = m_MapBlockRowNum * MAP_BLOCK_HEIGHT;

        // 读取块地址
        xStream >> ReadBytesAssist(m_ArrayBlockOffset, sizeof(quint32) * m_MapBlockRowNum * m_MapBlockColNum);

        // 读取遮罩数据头
        xStream >> m_MaskHead;

        // 读取遮罩地址
        xStream >> ReadBytesAssist(m_ArrayMaskOffset, sizeof(quint32) * m_MaskHead.m_MaskNum);

        // 申请障碍数据内存空间
        m_BarrierWidth = GetMapHeader_Width() / MAP_BARRIER_LATTICE_PIXEL_WIDTH_SIZE;
        m_BarrierHeight = GetMapHeader_Height() / MAP_BARRIER_LATTICE_PIXEL_HEIGHT_SIZE;
        m_BarrierData.reset(NEW quint8[m_MapBlockRowNum * m_MapBlockColNum * MAP_BARRIER_WIDTH * MAP_BARRIER_HEIGHT]);
        m_BarrierData_ = m_BarrierData.get();
        memset(m_BarrierData_, 1, m_MapBlockRowNum * m_MapBlockColNum * MAP_BARRIER_WIDTH * MAP_BARRIER_HEIGHT);

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
            //    //Int32 xIndex = this->GetIndexByPos(lpMask->m_MaskInfo.m_StartX, lpMask->m_MaskInfo.m_StartY);
            //    FAST_FOREACH(xMask->m_SetBlockIndex)
            //    {
            //        Int32 xIndex = xEnumValue;
            //        if (!m_Dict_MapMasks.ContainsKey(xIndex))
            //        {
            //            m_Dict_MapMasks.Add(xIndex, ListMapMask());
            //        }
            //        m_Dict_MapMasks[xIndex].m_Masks.Add(xMask);
            //    }
            //}
        }
    }
    else if (MAP_M3_0_HEADER_FLAG == m_MapHeaderFlag)
    {
        xStream >> m_MapHeader_3_0;

        // 计算分块数量
        m_MapBlockColNum = GetMapHeader_Width() / MAP_BLOCK_WIDTH; if (GetMapHeader_Width() % MAP_BLOCK_WIDTH != 0) { m_MapBlockColNum++; }
        m_MapBlockRowNum = GetMapHeader_Height() / MAP_BLOCK_HEIGHT; if (GetMapHeader_Height() % MAP_BLOCK_HEIGHT != 0) { m_MapBlockRowNum++; }

        // 计算图片尺寸
        m_MapBmpWidth = m_MapBlockColNum * MAP_BLOCK_WIDTH;
        m_MapBmpHeight = m_MapBlockRowNum * MAP_BLOCK_HEIGHT;

        // 读取块地址
        xStream >> ReadBytesAssist(m_ArrayBlockOffset, sizeof(quint32) * m_MapBlockRowNum * m_MapBlockColNum);
        //m_ArrayBlockOffsetCount = m_MapBlockRowNum * m_MapBlockColNum;
        //m_ArrayBlockOffset = NEW DWORD[m_ArrayBlockOffsetCount];
        //ARRAY_READ_MEMORY_ASSIST(m_MapDataOffset, m_ArrayBlockOffset, sizeof(DWORD) * m_ArrayBlockOffsetCount, "地图块地址");

        // 读取遮罩数据头
        xStream >> m_MaskHead;

        // 读取遮罩地址
        xStream >> ReadBytesAssist(m_ArrayMaskOffset, sizeof(quint32) * m_MaskHead.m_MaskNum);

        // 申请障碍数据内存空间
        m_BarrierWidth = GetMapHeader_Width() / MAP_BARRIER_LATTICE_PIXEL_WIDTH_SIZE;
        m_BarrierHeight = GetMapHeader_Height() / MAP_BARRIER_LATTICE_PIXEL_HEIGHT_SIZE;
        m_BarrierData.reset(NEW quint8[m_MapBlockRowNum * m_MapBlockColNum * MAP_BARRIER_WIDTH * MAP_BARRIER_HEIGHT]);
        m_BarrierData_ = m_BarrierData.get();
        memset(m_BarrierData_, 1, m_MapBlockRowNum * m_MapBlockColNum * MAP_BARRIER_WIDTH * MAP_BARRIER_HEIGHT);

        // 准备读取单元
        xFile.seek(m_MapHeader_3_0.CellDataAddr);
        BlockUnitInfo xCellUnitInfo;
        xStream >> xCellUnitInfo;

        //LPBYTE xData = NEW BYTE[xCellUnitInfo.m_Size];
        //ARRAY_READ_MEMORY_ASSIST(m_MapDataOffset, xData, xCellUnitInfo.m_Size, "");
        return True;
    }
    return False;
}

