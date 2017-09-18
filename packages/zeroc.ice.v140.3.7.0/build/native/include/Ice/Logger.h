// **********************************************************************
//
// Copyright (c) 2003-2017 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************
//
// Ice version 3.7.0
//
// <auto-generated>
//
// Generated from file `Logger.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

#ifndef __Ice_Logger_h__
#define __Ice_Logger_h__

#include <IceUtil/PushDisableWarnings.h>
#include <Ice/ProxyF.h>
#include <Ice/ObjectF.h>
#include <Ice/ValueF.h>
#include <Ice/Exception.h>
#include <Ice/LocalObject.h>
#include <Ice/StreamHelpers.h>
#include <Ice/Comparable.h>
#include <IceUtil/ScopedArray.h>
#include <Ice/Optional.h>
#include <IceUtil/UndefSysMacros.h>

#ifndef ICE_IGNORE_VERSION
#   if ICE_INT_VERSION / 100 != 307
#       error Ice version mismatch!
#   endif
#   if ICE_INT_VERSION % 100 > 50
#       error Beta header file detected
#   endif
#   if ICE_INT_VERSION % 100 < 0
#       error Ice patch level mismatch!
#   endif
#endif

#ifndef ICE_API
#   if defined(ICE_STATIC_LIBS)
#       define ICE_API /**/
#   elif defined(ICE_API_EXPORTS)
#       define ICE_API ICE_DECLSPEC_EXPORT
#   else
#       define ICE_API ICE_DECLSPEC_IMPORT
#   endif
#endif

#ifdef ICE_CPP11_MAPPING // C++11 mapping

namespace Ice
{

class Logger;

}

namespace Ice
{

class ICE_CLASS(ICE_API) Logger
{
public:

    ICE_MEMBER(ICE_API) virtual ~Logger();

    virtual void print(const ::std::string&) = 0;

    virtual void trace(const ::std::string&, const ::std::string&) = 0;

    virtual void warning(const ::std::string&) = 0;

    virtual void error(const ::std::string&) = 0;

    virtual ::std::string getPrefix() = 0;

    virtual ::std::shared_ptr<::Ice::Logger> cloneWithPrefix(const ::std::string&) = 0;
};

}

namespace Ice
{

}

namespace Ice
{

using LoggerPtr = ::std::shared_ptr<Logger>;

}

#else // C++98 mapping

namespace Ice
{

class Logger;
ICE_API ::Ice::LocalObject* upCast(::Ice::Logger*);
typedef ::IceInternal::Handle< ::Ice::Logger> LoggerPtr;

}

namespace Ice
{

class ICE_API Logger : public virtual ::Ice::LocalObject
{
public:

    typedef LoggerPtr PointerType;

    virtual ~Logger();

    virtual void print(const ::std::string&) = 0;

    virtual void trace(const ::std::string&, const ::std::string&) = 0;

    virtual void warning(const ::std::string&) = 0;

    virtual void error(const ::std::string&) = 0;

    virtual ::std::string getPrefix() = 0;

    virtual ::Ice::LoggerPtr cloneWithPrefix(const ::std::string&) = 0;
};

inline bool operator==(const Logger& lhs, const Logger& rhs)
{
    return static_cast<const ::Ice::LocalObject&>(lhs) == static_cast<const ::Ice::LocalObject&>(rhs);
}

inline bool operator<(const Logger& lhs, const Logger& rhs)
{
    return static_cast<const ::Ice::LocalObject&>(lhs) < static_cast<const ::Ice::LocalObject&>(rhs);
}

}

namespace Ice
{

}

#endif

#include <IceUtil/PopDisableWarnings.h>
#endif
