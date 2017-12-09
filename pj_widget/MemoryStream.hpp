#pragma once

class MemoryStream
{
public:
    MemoryStream(DWORD dwBufferSize = 8192)
        : m_spBuffer(NEW uint8_t[dwBufferSize], [](LPBYTE slpBuffer) { SAFE_DELETE_ARRAY(slpBuffer); })
        , m_BufferSize(dwBufferSize)
        , m_InOffect(0)
        , m_OutOffect(0)
        , m_IsNeedFree(True)
    {
        ;
    }

    MemoryStream(LPBYTE lpBuffer, DWORD dwBufferSize)
        : m_spBuffer(lpBuffer, [](LPBYTE slpBuffer) {; })
        , m_BufferSize(dwBufferSize)
        , m_InOffect(0)
        , m_OutOffect(0)
        , m_IsNeedFree(False)
    {
        ;
    }

    ~MemoryStream()
    {
        if (m_IsNeedFree)
        {
            //SAFE_DELETE_ARRAY(m_spBuffer);
        }
    }

    template<class TP>
    MemoryStream& operator >> (TP& xParam)
    {
        if (m_OutOffect + sizeof(TP) <= m_BufferSize)
        {
            xParam = *((TP*)(m_spBuffer.get() + m_OutOffect));
            m_OutOffect += sizeof(TP);
        }
        else { throw "内存流越界!"; }
        return *this;
    }

    MemoryStream& Read(LPVOID xData, DWORD xLen)
    {
        if (m_OutOffect + xLen <= m_BufferSize)
        {
            memcpy(xData, m_spBuffer.get() + m_OutOffect, xLen);
            m_OutOffect += xLen;
        }
        else { throw "内存流越界!"; }
        return *this;
    }

    template<class TP>
    MemoryStream& operator << (TP& xParam)
    {
        if (m_InOffect + sizeof(TP) <= m_BufferSize)
        {
            *((TP*)(m_spBuffer.get() + m_InOffect)) = xParam;
            m_InOffect += sizeof(TP);
        }
        else { throw "内存流越界!"; }
        return *this;
    }

    MemoryStream& Write(LPVOID xData, DWORD xLen)
    {
        if (m_InOffect + xLen <= m_BufferSize)
        {
            memcpy(m_spBuffer.get() + m_InOffect, xData, xLen);
            m_InOffect += xLen;
        }
        else { throw "内存流越界!"; }
        return *this;
    }

    DWORD GetOutSurplusSize() { return m_BufferSize - m_OutOffect; }
    DWORD GetInSurplusSize() { return m_BufferSize - m_InOffect; }
    DWORD GetBuffSize() { return m_BufferSize; }
    LPBYTE GetBuff() { return m_spBuffer.get(); }
    LPBYTE GetBuff(DWORD& dwOutOffect, DWORD& dwInOffect) { dwOutOffect = m_OutOffect; dwInOffect = m_InOffect; return m_spBuffer.get(); }

    Boolean OutSeek(DWORD dwOffect)
    {
        if (dwOffect >= 0 && dwOffect < m_BufferSize)
        {
            m_OutOffect = dwOffect;
            return True;
        }
        return False;
    }

    Boolean InSeek(DWORD dwOffect)
    {
        if (dwOffect >= 0 && dwOffect < m_BufferSize)
        {
            m_InOffect = dwOffect;
            return True;
        }
        return False;
    }

private:
    Boolean m_IsNeedFree;
    DWORD   m_InOffect;
    DWORD   m_OutOffect;
    SafePtr<uint8_t> m_spBuffer;
    DWORD   m_BufferSize;
};


#define READ_MEMORY_ASSIST(memory, type, name)  memcpy(&type, memory, sizeof(type)); memory += sizeof(type);
#define ARRAY_READ_MEMORY_ASSIST(memory, buffaddr, len, name)  memcpy(buffaddr, memory, len); memory += len;
#define ADD_MEMORY_POS(memory, pos) memory += pos;
#define SUB_MEMORY_POS(memory, pos) memory -= pos;

#ifdef _DEBUG
#define READ_FILE_ASSIST(file, type, name)              msAssert(1 == fread(&type, sizeof(type), 1, file),          #type"读取["#name"]失败!"); msAssertLog(#type"读取["#name"][%lld]", (int64_t)ftell(file));
#define READ_FILE_ASSIST_ARRAY(file, type, count, name) msAssert(count == fread(type, sizeof(*type), count, file),  #type"读取["#name"]失败!"); msAssertLog(#type"读取["#name"][%lld]", (int64_t)ftell(file));
#else
#define READ_FILE_ASSIST(file, type, name)              msAssert(1 == fread(&type, sizeof(type), 1, file),          #type"读取["#name"]失败!");
#define READ_FILE_ASSIST_ARRAY(file, type, count, name) msAssert(count == fread(type, sizeof(*type), count, file),  #type"读取["#name"]失败!");
#endif // DEBUG


#define ADD_FILE_POS(file, pos) fseek(file, pos, SEEK_CUR);
#define SUB_FILE_POS(file, pos) fseek(file, -pos, SEEK_CUR);

#define AUTO_SET_POINTER_ASSIST(file, basememory, memory, pos)\
{\
    if (file != nullptr)\
    {\
        fseek(file, pos, SEEK_SET);\
    }\
    else if (memory)\
    {\
        memory = basememory + pos;\
    }\
    else\
    {\
        msAssertLog("设定游标失败!");\
    }\
}

#define AUTO_READ_LEN_ASSIST(file, memory, addr, len, name)\
{\
    if (file != nullptr)\
    {\
        READ_FILE_ASSIST_ARRAY(file, addr, len, name);\
    }\
    else if (memory)\
    {\
        ARRAY_READ_MEMORY_ASSIST(memory, addr, len, name);\
    }\
    else\
    {\
        msAssertLog("读取[%s]失败!", name);\
    }\
}

#define AUTO_READ_ASSIST(file, memory, type, name)\
{\
    if (file != nullptr)\
    {\
        READ_FILE_ASSIST(file, type, name);\
    }\
    else if (memory)\
    {\
        READ_MEMORY_ASSIST(memory, type, name);\
    }\
    else\
    {\
        msAssertLog("读取[%s]失败!", name);\
    }\
}

