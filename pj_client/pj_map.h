#pragma once
#include <QtWidgets/QGraphicsItem>
#include <QtGui/QPainter>
#include <QtCore/QTime>
#include "pj_loader.h"

#define MAP_MAPX_HEADER_FLAG    0x4D415058
#define MAP_M1_0_HEADER_FLAG    0x4D312E30
#define MAP_M3_0_HEADER_FLAG    0x4D332E30

#define MAP_BARRIER_LATTICE_PIXEL_WIDTH_SIZE    20
#define MAP_BARRIER_LATTICE_PIXEL_HEIGHT_SIZE   20

#define MAP_JPGH_FLAG           0x4A504748
#define MAP_GEPJ_FLAG           0x4A504547
#define MAP_CELL_FLAG           0x43454C4C
#define MAP_BLOK_FLAG           0x424C4F4B
#define MAP_MASK_FLAG           0x4D41534B
#define MAP_IMAG_FLAG           0x494D4147
#define MAP_MSK2_FLAG           0x4D534B32
#define MAP_ROL0_FLAG           0x524F4C30
#define MAP_BRIG_FLAG           0x42524947
#define MAP_LIGT_FLAG           0x4C494754
#define MAP_DNE__FLAG           0x454E4420

#pragma pack(push)
#pragma pack(1)
// ��ͼͷ
struct MapHeader_1_0
{
    qint32 Width;
    qint32 Height;
};
struct MapHeader_3_0
{
    quint32 CellDataAddr;   // ��Ԫ��ʼ��ַ
    quint32 Width;          // ��ͼʵ�ʵĿ��
    quint32 Height;         // ��ͼʵ�ʵĸ߶�
    quint16 PointWidth;     // ����Ŀ��(Ĭ�ϣ�20px)
    quint16 PointHeight;    // ����ĸ߶�(Ĭ�ϣ�20px)
    quint16 SubWidth;       // С��ͼ�Ŀ��(Ĭ�ϣ�400px)
    quint16 SubHeight;      // С��ͼ�ĸ߶�(Ĭ�ϣ�320px)
    quint32 UnitIndexOffset;// ��Ԫ������λ��
    quint32 UnitIndexNum;   // ��Ԫ����������
    quint32 IndexOffset;    // ������λ��(δ֪����)
    quint32 IndexNum;       // ����������(δ֪����)
};

// ��ͼ����Ϣ
struct BlockUnitInfo { quint32 m_Flag; qint32 m_Size; };

struct BlockUnitData
{
    quint32  m_Flag = 0;
    qint32  m_Size = 0;
    std::shared_ptr<quint8> m_Data;
};

// �赲������Ϣ
struct BarrierDataInfo
{
    qint32 m_BarrierBytesNum;
    quint8* m_Data;
};

class MapUnit
{
public:
    ~MapUnit() { SAFE_DELETE_ARRAY(m_ArrayUnitAddr); }
    quint32* m_ArrayUnitAddr = nullptr;
    qint32 m_UnitCount = 0;
};

// ��ͼ����ͷ
struct MaskHead
{
    quint32 m_Unknown;
    qint32 m_MaskNum;
};

// JPEG����ͷ
struct JPEGCommonHead
{
    quint32 m_Flag;
    qint32 m_Size;
    quint8* m_Data;
};


inline quint32 _MAP_BLOCK_WIDTH(quint32 xHeader)
{
    switch (xHeader)
    {
        case 0x4D415058:
        case 0x4D312E30: { return 320; }

        case 0x4D322E35:
        case 0x4D332E30:
        case 0x524F4C30: { return 400; }
    }
    return INVALID_NID;
}
#define MAP_BLOCK_WIDTH (_MAP_BLOCK_WIDTH(m_MapHeaderFlag))

inline quint32 _MAP_BLOCK_HEIGHT(quint32 xHeader)
{
    switch (xHeader)
    {
        case 0x4D415058:
        case 0x4D312E30: { return 240; }

        case 0x4D322E35:
        case 0x4D332E30:
        case 0x524F4C30: { return 320; }
    }
    return INVALID_NID;
}
#define MAP_BLOCK_HEIGHT (_MAP_BLOCK_HEIGHT(m_MapHeaderFlag))

inline qint32 _MAP_BARRIER_LATTICE_PIXEL_WIDTH_SIZE(qint32 xHeader, MapHeader_1_0& xMapHeader_1_0, MapHeader_3_0& xMapHeader_3_0)
{
    switch (xHeader)
    {
        case 0x4D322E35:
        case 0x4D332E30:
        case 0x524F4C30: { return xMapHeader_3_0.PointWidth; }
    }
    return 20;
}
inline qint32 _MAP_BARRIER_LATTICE_PIXEL_HEIGHT_SIZE(qint32 xHeader, MapHeader_1_0& xMapHeader_1_0, MapHeader_3_0& xMapHeader_3_0)
{
    switch (xHeader)
    {
        case 0x4D322E35:
        case 0x4D332E30:
        case 0x524F4C30: { return xMapHeader_3_0.PointHeight; }
    }
    return 20;
}

inline qint32 _MAP_BARRIER_WIDTH(qint32 xHeader, MapHeader_1_0& xMapHeader_1_0, MapHeader_3_0& xMapHeader_3_0) { return _MAP_BLOCK_WIDTH(xHeader) / _MAP_BARRIER_LATTICE_PIXEL_WIDTH_SIZE(xHeader, xMapHeader_1_0, xMapHeader_3_0); }
#define MAP_BARRIER_WIDTH (_MAP_BARRIER_WIDTH(m_MapHeaderFlag,m_MapHeader_1_0,m_MapHeader_3_0))
inline qint32 _MAP_BARRIER_HEIGHT(qint32 xHeader, MapHeader_1_0& xMapHeader_1_0, MapHeader_3_0& xMapHeader_3_0) { return _MAP_BLOCK_HEIGHT(xHeader) / _MAP_BARRIER_LATTICE_PIXEL_HEIGHT_SIZE(xHeader, xMapHeader_1_0, xMapHeader_3_0); }
#define MAP_BARRIER_HEIGHT (_MAP_BARRIER_HEIGHT(m_MapHeaderFlag,m_MapHeader_1_0,m_MapHeader_3_0))


#pragma pack(pop)

class pj_map;
class pj_mapCell : public QGraphicsItem
{
public:
    pj_mapCell(pj_map* _pj_map, quint32 mapHeaderFlag) :m_pj_map(_pj_map), m_MapHeaderFlag(mapHeaderFlag) {}

    virtual QRectF boundingRect() const;
    virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = Q_NULLPTR);

private:
    friend class pj_map;
    quint32 m_MapHeaderFlag;
    pj_map* m_pj_map = nullptr;

    quint32 m_UnitCount;
    std::shared_ptr<quint32> m_UnitAddr;
    //LPBYTE m_lpData = nullptr;
    //GameSprite* m_BlockSprite = nullptr;
    //MsList<MapMask*> m_ListMapMask;
    QVector<std::shared_ptr<BlockUnitData>> m_mask; // MASK ����
    std::shared_ptr<BlockUnitData> m_imag;  // IMAG
    std::shared_ptr<BlockUnitData> m_msk2;  // MSK2
    std::shared_ptr<BlockUnitData> m_jpgh;  // JPGH
    std::shared_ptr<BlockUnitData> m_blok;  // BLOK
    std::shared_ptr<BlockUnitData> m_cell;  // CELL
    std::shared_ptr<BlockUnitData> m_brig;  // BRIG
    std::shared_ptr<BlockUnitData> m_ligt;  // LIGT
    std::shared_ptr<BlockUnitData> m_head;  // HEAD
    std::shared_ptr<BlockUnitData> m_jpeg;  // JPEG
    std::shared_ptr<BlockUnitData> m_rol0;  // ROL0

    std::shared_ptr<QImage> m_blockImage;
};

class pj_wasani;
class pj_map : public QGraphicsScene
{
public:

    pj_map(QString&& file);

    Boolean load();
    Boolean ReadBlockUnit(QDataStream& xStream, pj_mapCell* mapCell);
    Boolean ReadBlockUnitCellOnly(QDataStream& xStream, pj_mapCell* mapCell);
    pj_mapCell* readCellData(quint32 cellAddr);

public:
    QVector<pj_mapCell*> _mapCellVector;
    QVector<pj_wasani*> aniVector;
    //QGraphicsTextItem* m_QGraphicsTextItem;

private:
    QFile m_File;

    inline qint32 GetMapHeader_Width()
    {
        switch (m_MapHeaderFlag)
        {
            case MAP_M1_0_HEADER_FLAG: {return m_MapHeader_1_0.Width; }
            case MAP_M3_0_HEADER_FLAG: {return m_MapHeader_3_0.Width; }
        }
        return INVALID_NID;
    }

    inline qint32 GetMapHeader_Height()
    {
        switch (m_MapHeaderFlag)
        {
            case MAP_M1_0_HEADER_FLAG: {return m_MapHeader_1_0.Height; }
            case MAP_M3_0_HEADER_FLAG: {return m_MapHeader_3_0.Height; }
        }
        return INVALID_NID;
    }

    quint32 m_MapHeaderFlag;
    quint32 m_MapBlockRowNum;    // ��ͼ�������
    quint32 m_MapBlockColNum;    // ��ͼ�������
    quint32 m_MapBmpWidth;
    quint32 m_MapBmpHeight;
    MapHeader_1_0 m_MapHeader_1_0;
    MapHeader_3_0 m_MapHeader_3_0;

    // �����ݵ�ַ�б�
    std::shared_ptr<quint32> m_ArrayBlockOffset;

    // ��������ͷ
    MaskHead m_MaskHead;
    quint8* m_JPGHData;
    quint32 m_JPGHSize;

    // �������ݵ�ַ�б�
    std::shared_ptr<quint32> m_ArrayMaskOffset;


    // �ϰ�����
    qint32 m_BarrierWidth;
    qint32 m_BarrierHeight;
    std::shared_ptr<quint8> m_BarrierData;
    quint8* m_BarrierData_ = nullptr;
    inline Boolean CheckWayCanGo(qint32 x, qint32 y)
    {
        if (x > 0 && y > 0 && x < m_BarrierWidth && y < m_BarrierHeight)
        {
            return m_BarrierData_[y * m_BarrierWidth + x] == 0;
        }
        return False;
    }

};

