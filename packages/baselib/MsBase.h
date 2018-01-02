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
#else
#define ZH_CN "zh_CN.GB18030"
#endif

#if defined(_DEBUG) && defined(WIN)
#include <crtdbg.h>
#define BEGIN_INIT _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#define NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#else
#define BEGIN_INIT
#define NEW new
#endif

typedef bool Boolean;
#define True true
#define False false

typedef float   Single;
typedef double  Double;
typedef void*   IntPtr;

//无效的ID值
#define INVALID_LID (int64_t)(-1)
#define INVALID_QID (uint64_t)(-1)
#define INVALID_NID (int32_t)(-1)
#define INVALID_UID (uint32_t)(-1)
#define INVALID_WID (uint16_t)(-1)
#define INVALID_PTR (IntPtr)(-1)


#define SafePtr std::shared_ptr
#define AutoLeaveRun        std::shared_ptr<void> _leaveRun(nullptr, [](void*)
#define AutoLeaveRunThis    std::shared_ptr<void> _leaveRun(nullptr, [this](void*)
#define AutoBuff(buff, size)    SafePtr<uint8_t> xTemp##__LINE__(NEW uint8_t[size], [](LPBYTE x) { SAFE_DELETE_ARRAY(x); }); LPBYTE buff = xTemp##__LINE__.get()

#define LAMBDA_NOTHING(type)        [](type*) { ; }
#define LAMBDA_DELETE(type)         [](type* x) { delete x; }
#define LAMBDA_DELETE_ARRAY(type)   [](type* x) { delete[] x; }
#define LAMBDA_RELEASE(type)        [](type* x) { x->release(); }
#define LAMBDA_CLOSE(type)          [](type* x) { x->close(); }

#define LAMBDA_AUTO_NEW_NOTHING(type)                   NEW type(), LAMBDA_NOTHING(type)
#define LAMBDA_AUTO_NEW_NOTHING_P1(type,P1)             NEW type(P1), LAMBDA_NOTHING(type)
#define LAMBDA_AUTO_NEW_NOTHING_P2(type,P1,P2)          NEW type(P1,P2), LAMBDA_NOTHING(type)
#define LAMBDA_AUTO_NEW_NOTHING_P3(type,P1,P2,P3)       NEW type(P1,P2,P3), LAMBDA_NOTHING(type)
#define LAMBDA_AUTO_NEW_NOTHING_P4(type,P1,P2,P3,P4)    NEW type(P1,P2,P3,P4), LAMBDA_NOTHING(type)
#define LAMBDA_AUTO_NEW_DELETE(type)                    NEW type(), LAMBDA_DELETE(type)
#define LAMBDA_AUTO_NEW_DELETE_P1(type,P1)              NEW type(P1), LAMBDA_DELETE(type)
#define LAMBDA_AUTO_NEW_DELETE_P2(type,P1,P2)           NEW type(P1,P2), LAMBDA_DELETE(type)
#define LAMBDA_AUTO_NEW_DELETE_P3(type,P1,P2,P3)        NEW type(P1,P2,P3), LAMBDA_DELETE(type)
#define LAMBDA_AUTO_NEW_DELETE_P4(type,P1,P2,P3,P4)     NEW type(P1,P2,P3,P4), LAMBDA_DELETE(type)
#define LAMBDA_AUTO_NEW_DELETE_ARRAY(type,len)          NEW type[len], LAMBDA_DELETE_ARRAY(type)
#define LAMBDA_AUTO_NEW_RELEASE(type)                   NEW type(), LAMBDA_RELEASE(type)
#define LAMBDA_AUTO_NEW_CLOSE(type)                     NEW type(), LAMBDA_CLOSE(type)

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

#define FORRANGE(_num)             for (qint32 i = 0; i < _num; i++)


#include <QtCore/QFile>
#include <QtCore/QBuffer>

#include <QtWidgets/QWidget>
#include <QtWidgets/QGroupBox>
#include <QtMultimedia/QMediaPlayer>

struct ReadBytesAssist
{
    inline ReadBytesAssist(void* p, quint32 l)
    {
        data = (char*)p;
        len = l;
    }

    template <typename T>
    inline ReadBytesAssist(std::shared_ptr<T>& sp, quint32 l)
    {
        sp.reset(NEW T[l]);
        data = (char*)sp.get();
        len = l;
    }
    char* data;
    quint32 len;
};

inline QDataStream& operator>>(QDataStream &s, ReadBytesAssist &c)
{
    s.readRawData(c.data, c.len);
    return s;
}

template <typename T>
inline QDataStream& operator>>(QDataStream &s, T &c)
{
    s.readRawData((char*)&(c), sizeof(c));
    return s;
}



#endif  // __MS_BASE_H__
