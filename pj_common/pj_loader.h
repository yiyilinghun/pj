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
    // 加载资源文件
    Boolean pjLoadFile(QString filename, uint32_t filekey);

    // 获取资源总数
    uint32_t pjGetUnitSum();

    // 获取动画纹理数量(64位前32位代表朝向数量,后32位代表帧数)
    Boolean pjGetWasTextureSum(quint64 unitKey, quint64 texSum, quint64 texSize);

    //// 加载动画列表
    //Boolean pjGetWasTextures(xyTextureInfo* ptrTextureInfo, int32_t& textureSum);

    // 加载动画
    Boolean pjGetWasTextures(quint64 unitKey, xyTextureInfo& textureInfo, QVector<QImage*>& imageVector);

    // 资源map
    QHash<quint64, xyUnit> m_hashReses;

    // 资源文件key,文件路径名对应map
    QHash<uint32_t, QString> m_hashReskeyResFilename;

    // 资源是否已加载(map存在说明尝试加载过,否则未加载, value=true 加载成功, value=false 加载失败)
    QHash<uint32_t, Boolean> m_hashLoadedRes;

    //QHash<quint64, std::shared_ptr<QChar>> m_hashResData;
};

extern std::shared_ptr<pjResManager> g_ms_pjResManager;
extern pjResManager& pj_GetResManager();


// 加载资源文件
Boolean LoadFile(const char* filename, uint32_t filekey);

// 获取资源总数
uint32_t GetUnitSum();

// 获取动画纹理数量(64位前32位代表朝向数量,后32位代表帧数)
Boolean GetWasTextureSum(quint64 unitKey, quint64 texSum, quint64 texSize);

//// 加载动画列表
//Boolean GetWasTextures(xyTextureInfo* ptrTextureInfo, int32_t& textureSum);
