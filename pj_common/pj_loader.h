#pragma once
#include <QtCore/QDataStream>

//QDataStream
#define FAST_LAMBDA_DELETE          [](void* d) { SAFE_DELETE(d); }
#define FAST_LAMBDA_DELETE_ARRAY    [](void* d) { SAFE_DELETE_ARRAY(d); }
#define FAST_LAMBDA_CALL(fun)       [](auto d) { fun(d); }

#define WAS_MAKE_ARGB(c, a) (a << 24) + (c << 8 & 0xf80000) + (c << 5 & 0x7fc00) + (((c << 3 | (c & 7)) & 0x3ff))

#ifdef PJ_EXPORTS
#define PJ_COMMON_LIB_API __declspec(dllexport)
#else
#define PJ_COMMON_LIB_API __declspec(dllimport)
#endif

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
};

struct xyTextureInfo
{
    IntPtr textureHandle = nullptr;
    uint64_t resKey;
    uint64_t wasKey;
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

class PJ_COMMON_LIB_API pjResManager
{
public:
    // ������Դ�ļ�
    Boolean pjLoadFile(QString filename, uint32_t filekey);

    // ��ȡ��Դ����
    uint32_t pjGetUnitSum();

    // ��ȡ������������(64λǰ32λ����������,��32λ����֡��)
    Boolean pjGetWasTextureSum(uint64_t unitKey, uint64_t texSum, uint64_t texSize);

    //// ���ض����б�
    //Boolean pjGetWasTextures(xyTextureInfo* ptrTextureInfo, int32_t& textureSum);

    // ���ض���
    Boolean pjGetWasTextures(xyTextureInfo& textureInfo, std::vector<QBuffer*>& xListTexStream);

    // ��Դmap
    std::map<uint64_t, xyUnit> m_mapReses;

    // ��Դ�ļ�key,�ļ�·������Ӧmap
    std::map<uint32_t, QString> m_mapReskey_ResFilename;

    // ��Դ�Ƿ��Ѽ���(map����˵�����Լ��ع�,����δ����, value=true ���سɹ�, value=false ����ʧ��)
    std::map<uint32_t, Boolean> m_mapLoadedRes;
};

extern pjResManager g_pjResManager;


// ������Դ�ļ�
Boolean LoadFile(const char* filename, uint32_t filekey);

// ��ȡ��Դ����
uint32_t GetUnitSum();

// ��ȡ������������(64λǰ32λ����������,��32λ����֡��)
Boolean GetWasTextureSum(uint64_t unitKey, uint64_t texSum, uint64_t texSize);

//// ���ض����б�
//Boolean GetWasTextures(xyTextureInfo* ptrTextureInfo, int32_t& textureSum);
