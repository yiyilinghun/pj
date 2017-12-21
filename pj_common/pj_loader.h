#pragma once
#include <QtCore/QDataStream>

#pragma pack(push)
#pragma pack(1)
struct xyUnit
{
    enum E_UNIT_TYPE
    {
        EUT_UNKNOW,
        EUT_WAS,
        EUT_BMP,
        EUT_RIFF,
        EUT_TGA,
        EUT_MP3,
        EUT_WAV,
    };

    struct UnitFileInfo
    {
        uint32_t m_Key;
        uint32_t m_Addr;
        uint32_t m_Len;
        uint32_t m_UnKnow;
    };

    UnitFileInfo m_UnitFileInfo;
    E_UNIT_TYPE m_resType = E_UNIT_TYPE::EUT_UNKNOW;

    quint16 m_imageHeaderSize;
    quint16 m_directionCount;
    quint16 m_frameCount;
    quint16 m_width;
    quint16 m_height;
    qint16 m_hotX;
    qint16 m_hotY;
    std::shared_ptr<char> m_resOriginalData;
    QVector<std::shared_ptr<uint32_t>> m_resProductDatas;
    QVector<std::shared_ptr<QImage>> m_ProductImages;
};

struct xyTextureInfo
{
    IntPtr textureHandle = nullptr;
    quint64 resKey = 0;
    quint64 wasKey = 0;
    int32_t width;
    int32_t height;
    int32_t hotX;
    int32_t hotY;
};

struct WPixel
{
    union { uint16_t m_Color/*16bit*/; struct { uint16_t Blue : 5/*5bit*/; uint16_t Green : 6/*6bit*/; uint16_t Red : 5/*5bit*/; }S_TEMP; }; uint32_t MakeARGB(uint32_t A) { uint32_t R = (m_Color << 8 & 0xf80000); uint32_t G = (m_Color << 5 & 0x7fc00); uint32_t B = ((m_Color << 3 | (m_Color & 7)) & 0x3ff); uint32_t dwColor = (A << 24) + R + G + B; return dwColor; }; operator uint32_t() const { return (m_Color << 5 & 0x7fc00) | (m_Color << 8 & 0xf80000) | ((m_Color << 3 | (m_Color & 7)) & 0x3ff); }
};

struct WPixels
{
    WPixel m_Palette[256];
};
#pragma pack(pop)

class pjResManager
{
public:
    // ������Դ�ļ�
    Boolean pjLoadFile(QString filename, uint32_t filekey);

    // ��ȡ��Դ����
    uint32_t pjGetUnitSum();

    // ��ȡ������������(64λǰ32λ����������,��32λ����֡��)
    Boolean pjGetWasTextureSum(quint64 unitKey, quint64 texSum, quint64 texSize);

    //// ���ض����б�
    //Boolean pjGetWasTextures(xyTextureInfo* ptrTextureInfo, int32_t& textureSum);

    // ���ض���
    Boolean pjGetWasTextures(quint64 unitKey, xyTextureInfo& textureInfo, QVector<QImage*>& imageVector);

    // ��Դmap
    QHash<quint64, xyUnit> m_hashReses;

    // ��Դ�ļ�key,�ļ�·������Ӧmap
    QHash<uint32_t, QString> m_hashReskeyResFilename;

    // ��Դ�Ƿ��Ѽ���(map����˵�����Լ��ع�,����δ����, value=true ���سɹ�, value=false ����ʧ��)
    QHash<uint32_t, Boolean> m_hashLoadedRes;

    //QHash<quint64, std::shared_ptr<QChar>> m_hashResData;
};

extern std::shared_ptr<pjResManager> g_ms_pjResManager;
extern pjResManager& pj_GetResManager();


// ������Դ�ļ�
Boolean LoadFile(const char* filename, uint32_t filekey);

// ��ȡ��Դ����
uint32_t GetUnitSum();

// ��ȡ������������(64λǰ32λ����������,��32λ����֡��)
Boolean GetWasTextureSum(quint64 unitKey, quint64 texSum, quint64 texSize);

//// ���ض����б�
//Boolean GetWasTextures(xyTextureInfo* ptrTextureInfo, int32_t& textureSum);
