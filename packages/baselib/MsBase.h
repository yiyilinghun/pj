#pragma once
#ifndef __MS_BASE_H__
#define __MS_BASE_H__

#include <codecvt>
#include <string>
#include <iostream>
#include <future>
#include <ratio>
#include <chrono>
#include <iomanip>
#include <vector>
#include <functional>
#include <list>
#include <queue>
#include <mutex>
#include <thread>
#include <condition_variable>
#include <stdarg.h>


#ifdef WIN
#define ZH_CN "zh-CN"
#define U8(str) msStrAssist::m2u8(str)
#else
#define ZH_CN "zh_CN.GB18030"
#define U8(str) u8##str
#endif

typedef char Char;
typedef unsigned char Byte;

typedef signed short Int16;
typedef unsigned short Unt16;

typedef int Int32;
typedef unsigned int Unt32;

#ifdef WIN
typedef signed __int64 Int64;
typedef unsigned __int64 Unt64;
#else
typedef signed long long Int64;
typedef unsigned long long Unt64;
#endif

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

typedef Unt16   WORD;
typedef unsigned long   DWORD;
typedef Unt64   QWORD;
typedef size_t  TSIZE;


typedef void *IntPtr;

typedef std::wstring wstr;
typedef std::string mstr;
typedef std::string u8str;

#define ALLOCA_CH(size) (Char *)alloca(size)

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
#define var                 auto

#define msAssertLog(str, ...) ((_AssertLog(__FILE__, __LINE__, __FUNCTION__, "", str, ##__VA_ARGS__)))
void _AssertLog(const Char *file, DWORD line, const Char *func, const Char *expr, const Char *info, ...);

class msStrAssist
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
};



#include "MemoryList.hpp"
#include "MemoryVector.hpp"
#include "MemoryDictionary.hpp"



#endif  // __MS_BASE_H__
