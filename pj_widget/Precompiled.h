#pragma once

#include <stdarg.h>
#include <corecrt.h>
#include <corecrt_io.h>
#include <fcntl.h>
#include <stdio.h>
#include <tchar.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <codecvt>
#include <string>
#include <iostream>
#include <ratio>
#include <chrono>
#include <iomanip>
#include <functional>
#include <memory>

#include <vector>
#include <list>
#include <queue>
#include <map>
#include <unordered_map>


#if defined(_DEBUG) && defined(WIN)
#include <crtdbg.h>
#define BEGIN_INIT _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#define NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define DINLINE
#else
#define BEGIN_INIT
#define NEW new
#define DINLINE inline
#endif

typedef bool Boolean;
#define True true
#define False false

typedef float Single;
typedef double Double;

typedef uint16_t        WORD;
typedef unsigned long   DWORD;
typedef uint64_t        QWORD;
typedef size_t          TSIZE;
typedef uint8_t         *LPBYTE;
typedef DWORD           *LPDWORD;
typedef void            *LPVOID;
typedef int64_t         Time64;



typedef void *IntPtr;

typedef std::wstring wstr;
typedef std::string mstr;
typedef std::string u8str;

//无效的ID值
#define INVALID_LID         (Int64)(-1)
#define INVALID_QID         (QWORD)(-1)
#define INVALID_NID         (-1)
#define INVALID_UID         (DWORD)(-1)
#define INVALID_WID         (WORD)(-1)
#define INVALID_BID         (Byte)(-1)
#define INVALID_KEY         (LPVOID)(-1)
#define INVALID_VALUE       (-1)
#define INVALID_DVALUE      (DWORD)(-1)
#define INVALID_PTR         (IntPtr)(-1)


#define SafePtr std::shared_ptr
#define AutoLeaveRun(p1)        SafePtr<void> xTemp##__LINE__(nullptr, [](void*) { p1 })
#define AutoLeaveRunThis(p1)    SafePtr<void> xTemp##__LINE__(nullptr, [this](void*) { p1 })
#define AutoBuff(buff, size)    SafePtr<uint8_t> xTemp##__LINE__(NEW uint8_t[size], [](LPBYTE x) { SAFE_DELETE_ARRAY(x); }); LPBYTE buff = xTemp##__LINE__.get()

#ifndef SAFE_DELETE
#define SAFE_DELETE(p)          ((p) ? (delete (p), (p)=nullptr) : ((p) = (p)))
#endif
#ifndef SAFE_DELETE_ARRAY
#define SAFE_DELETE_ARRAY(p)    ((p)?(delete[] (p),(p)=nullptr):((p)=(p)))
#endif
#ifndef SAFE_RELEASE
#define SAFE_RELEASE(p)         ((p)?((p)->Release(),(p)=nullptr):((p) = (p)))
#endif
#ifndef SAFE_CLOSE
#define SAFE_CLOSE(p)           ((p) ? (::CloseHandle(p), (p)=nullptr) : ((p) = (p)))
#endif


#ifdef WIN
#define ZH_CN "zh-CN"
#else
#define ZH_CN "zh_CN.GB18030"
#endif

class msAssist
{
public:
    static mstr format(const char *xFormat, ...)
    {
        mstr xBuff;
        xBuff.resize(1024 * 10);
        va_list ap;
        va_start(ap, xFormat);
        int xRealLen = vsprintf((char*)xBuff.data(), xFormat, ap);
        xBuff.resize(xRealLen);
        va_end(ap);
        return xBuff;
    }

    static mstr m2u8(mstr& xMstr)
    {
        std::vector<wchar_t> buff(xMstr.size());
        std::locale loc(ZH_CN);
        wchar_t* pwszNext = nullptr;
        const char* pszNext = nullptr;
        mbstate_t state = {};
        int res = std::use_facet<std::codecvt<wchar_t, char, mbstate_t> >
            (loc).in(state,
                xMstr.data(), xMstr.data() + xMstr.size(), pszNext,
                buff.data(), buff.data() + buff.size(), pwszNext);

        if (std::codecvt_base::ok == res)
        {
            std::wstring_convert<std::codecvt_utf8<wchar_t>> cutf8;
            return cutf8.to_bytes(std::wstring(buff.data(), pwszNext));
        }
        return xMstr;
    }

    static mstr m2u8(mstr&& xMstr)
    {
        std::vector<wchar_t> buff(xMstr.size());
        std::locale loc(ZH_CN);
        wchar_t* pwszNext = nullptr;
        const char* pszNext = nullptr;
        mbstate_t state = {};
        int res = std::use_facet<std::codecvt<wchar_t, char, mbstate_t> >
            (loc).in(state,
                xMstr.data(), xMstr.data() + xMstr.size(), pszNext,
                buff.data(), buff.data() + buff.size(), pwszNext);

        if (std::codecvt_base::ok == res)
        {
            std::wstring_convert<std::codecvt_utf8<wchar_t>> cutf8;
            return cutf8.to_bytes(std::wstring(buff.data(), pwszNext));
        }
        return xMstr;
    }

    static mstr u82m(mstr& xU8str)
    {
        std::wstring_convert<std::codecvt_utf8<wchar_t>> cutf8;
        std::wstring wTemp = cutf8.from_bytes(xU8str);
        std::locale loc(ZH_CN);
        const wchar_t* pwszNext = nullptr;
        char* pszNext = nullptr;
        mbstate_t state = {};

        std::vector<char> buff(wTemp.size() * 2);
        int res = std::use_facet<std::codecvt<wchar_t, char, mbstate_t> >
            (loc).out(state,
                wTemp.data(), wTemp.data() + wTemp.size(), pwszNext,
                buff.data(), buff.data() + buff.size(), pszNext);

        if (std::codecvt_base::ok == res)
        {
            return std::string(buff.data(), pszNext);
        }
        return "";
    }

    static mstr u82m(mstr&& xU8str)
    {
        std::wstring_convert<std::codecvt_utf8<wchar_t>> cutf8;
        std::wstring wTemp = cutf8.from_bytes(xU8str);
        std::locale loc(ZH_CN);
        const wchar_t* pwszNext = nullptr;
        char* pszNext = nullptr;
        mbstate_t state = {};

        std::vector<char> buff(wTemp.size() * 2);
        int res = std::use_facet<std::codecvt<wchar_t, char, mbstate_t> >
            (loc).out(state,
                wTemp.data(), wTemp.data() + wTemp.size(), pwszNext,
                buff.data(), buff.data() + buff.size(), pszNext);

        if (std::codecvt_base::ok == res)
        {
            return std::string(buff.data(), pszNext);
        }
        return "";
    }



    static wstr u82w(mstr& xU8str)
    {
        std::wstring_convert<std::codecvt_utf8<wchar_t>> cutf8;
        std::wstring wTemp = cutf8.from_bytes(xU8str);
        return wTemp;
    }

    static wstr u82w(mstr&& xU8str)
    {
        std::wstring_convert<std::codecvt_utf8<wchar_t>> cutf8;
        std::wstring wTemp = cutf8.from_bytes(xU8str);
        return wTemp;
    }

    template <typename T>
    static mstr CreateStringByType(T& xT)
    {
        mstr xBuff;
        xBuff.resize(sizeof(xT));
        *((T*)(xBuff.data())) = xT;
        return xBuff;
    }

    template <typename T>
    static void CreateStringByType(mstr& xStr, T& xT)
    {
        xStr.resize(sizeof(xT));
        *((T*)(xStr.data())) = xT;
    }

    template <typename T>
    static T CreateTypeByString(mstr& xStr)
    {
        T xT;
        if (xStr.size() == sizeof(xT))
        {
            xT = *((T*)(xStr.data()));
        }
        return xT;
    }

    template <typename T>
    static void CreateTypeByString(T& xT, mstr& xStr)
    {
        if (xStr.size() == sizeof(xT))
        {
            xT = *((T*)(xStr.data()));
        }
    }

    inline static Time64 now()
    {
        return std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    }

    inline static mstr localtime(const char* tf = "%A %c")
    {
        auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        char mbstr[100];
        if (std::strftime(mbstr, sizeof(mbstr), tf, std::localtime(&t))) {
            return mbstr;
        }
        return "";
    }
};

#include "MemoryStream.hpp"

#ifndef BEGIN_ENUMERATOR

#define BEGIN_MULCONTAINER(key,container)       for (auto xIts = container.GetValues(key); xIts.first != container.GetEnd() && xIts.first != xIts.second; ++(xIts.first))
#define xMulKey                                 (xIts.first->first)
#define xMulValue                               (xIts.first->second)

#define xEnumValue                              (xContainer.Value())
#define xEnumKey                                (xContainer.Key())
//#define FAST_FOREACH(container)             {for (auto xEnumerator = (container).GetEnumerator(); xEnumerator.MoveNext();)
//#define FAST_FOREACH(container)             {for (auto xEnumerator = (container).GetEnumerator(); xEnumerator.MoveNext();)
//#define END_ENUMERATOR                          }
#define FOREACH_KEY_CALL(container,fun,...)     FAST_FOREACH(container){xEnumKey->fun(__VA_ARGS__);}
#define FOREACH_VALUE_CALL(container,fun,...)   FAST_FOREACH(container){xEnumValue->fun(__VA_ARGS__);}
#define ERASE_VALUE(container, value)           FAST_FOREACH(container) {if (value == xEnumValue){container.Erase(xEnumerator); break;}}
#define FOREACH_PROTO_REPEATED(repeated)        auto& _xTemp = repeated; for (int32_t i = 0; i < repeated->size(); i++)
#define xCurrentValue                           _xTemp->Mutable(i)
#define FOR_EACH_RANGE(it,pair_range)           for (auto it = pair_range.first; it != pair_range.second; ++it)

#endif

#ifndef FAST_FOREACH
#define FOREACH(container)                          for ((container).ToFirst(); (container).IsValid(); (container).DirectMoveNext())
#define NAME_FOREACH(name,container)                for (auto& name = (container).ForFirst(); name.IsValid(); name.DirectMoveNext())
#define FAST_FOREACH(container)                     for (auto& xContainer = (container).ForFirst(); xContainer.IsValid(); xContainer.DirectMoveNext())
#define SAFE_FOREACH(container)                     for (auto& xContainer = (container).ForFirst(); xContainer.IsValid(); xContainer.SafeMoveNext())

#define FOREACH_BACKWARD(container)                 for ((container).ToLast(); (container).IsValid(); (container).DirectMoveUp())
#define NAME_FOREACH_BACKWARD(name,container)       for (auto& name = (container).ForLast(); name.IsValid(); name.DirectMoveUp())
#define FAST_FOREACH_BACKWARD(container)            for (auto& xContainer = (container).ForLast(); xContainer.IsValid(); xContainer.DirectMoveUp())
#define SAFE_FOREACH_BACKWARD(container)            for (auto& xContainer = (container).ForLast(); xContainer.IsValid(); xContainer.SafeMoveUp())
#endif

#ifndef SAFE_ENUMERATOR_DELETE
//#define SAFE_ENUMERATOR_DELETE__(container)         FAST_FOREACH(xEnumerator##container, container) {auto lpTemp = xEnumerator##container.Value(); SAFE_DELETE(lpTemp);} container.Clear();
//#define SAFE_ENUMERATOR_DELETE_ARRAY__(container)   FAST_FOREACH(xEnumerator##container, container) {auto lpTemp = xEnumerator##container.Value(); SAFE_DELETE_ARRAY(lpTemp);} container.Clear();
#define SAFE_ENUMERATOR_DELETE(container)           FAST_FOREACH(container) {auto lpTemp = container.Value(); SAFE_DELETE(lpTemp);} container.Clear();
#define SAFE_ENUMERATOR_DELETE_ARRAY(container)     FAST_FOREACH(container) {auto lpTemp = container.Value(); SAFE_DELETE_ARRAY(lpTemp);} container.Clear();

#endif

#define msAssert(expr, str,...) ((expr) ? False : (_msAssertLog(__FILE__, __LINE__, __FUNCTION__, #expr"", str, ##__VA_ARGS__)))
#define msAssertLog(str, ...) ((_msAssertLog(__FILE__, __LINE__, __FUNCTION__, "", str, ##__VA_ARGS__)))
void _msCallbackAssertLog(mstr&& xAssertlog);
void _msAssertLog(const char *file, DWORD line, const char *func, const char *expr, const char *info, ...);

//#include "ResDef.h"
//#include "WdfDecoder.h"
//#include "WasDecoder.h"






