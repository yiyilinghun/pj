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

#include <QtCore/QFile>
#include <QtCore/QBuffer>

template <typename T>
QDataStream& operator>>(QDataStream &s, T &c)
{
    s.readRawData((char*)&(c), sizeof(c));
    return s;
}

#endif  // __MS_BASE_H__
