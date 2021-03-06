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
// Generated from file `EndpointInfo.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

#ifndef __IceSSL_EndpointInfo_h__
#define __IceSSL_EndpointInfo_h__

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
#include <Ice/Endpoint.h>
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

#ifndef ICESSL_API
#   if defined(ICE_STATIC_LIBS)
#       define ICESSL_API /**/
#   elif defined(ICESSL_API_EXPORTS)
#       define ICESSL_API ICE_DECLSPEC_EXPORT
#   else
#       define ICESSL_API ICE_DECLSPEC_IMPORT
#   endif
#endif

#ifdef ICE_CPP11_MAPPING // C++11 mapping

namespace IceSSL
{

class EndpointInfo;

}

namespace IceSSL
{

class ICE_CLASS(ICESSL_API) EndpointInfo : public ::Ice::EndpointInfo
{
public:

    ICE_MEMBER(ICESSL_API) virtual ~EndpointInfo();

    EndpointInfo() = default;

    EndpointInfo(const EndpointInfo&) = default;
    EndpointInfo(EndpointInfo&&) = default;
    EndpointInfo& operator=(const EndpointInfo&) = default;
    EndpointInfo& operator=(EndpointInfo&&) = default;

    EndpointInfo(const ::std::shared_ptr<::Ice::EndpointInfo>& iceP_underlying, int iceP_timeout, bool iceP_compress) :
        ::Ice::EndpointInfo(::std::move(iceP_underlying), iceP_timeout, iceP_compress)
    {
    }
};

}

namespace Ice
{

}

namespace IceSSL
{

using EndpointInfoPtr = ::std::shared_ptr<EndpointInfo>;

}

#else // C++98 mapping

namespace IceSSL
{

class EndpointInfo;
ICESSL_API ::Ice::LocalObject* upCast(::IceSSL::EndpointInfo*);
typedef ::IceInternal::Handle< ::IceSSL::EndpointInfo> EndpointInfoPtr;

}

namespace IceSSL
{

class ICESSL_API EndpointInfo : public ::Ice::EndpointInfo
{
public:

    typedef EndpointInfoPtr PointerType;

    virtual ~EndpointInfo();

    EndpointInfo()
    {
    }

    EndpointInfo(const ::Ice::EndpointInfoPtr& iceP_underlying, ::Ice::Int iceP_timeout, bool iceP_compress) :
        ::Ice::EndpointInfo(iceP_underlying, iceP_timeout, iceP_compress)
    {
    }
};

inline bool operator==(const EndpointInfo& lhs, const EndpointInfo& rhs)
{
    return static_cast<const ::Ice::LocalObject&>(lhs) == static_cast<const ::Ice::LocalObject&>(rhs);
}

inline bool operator<(const EndpointInfo& lhs, const EndpointInfo& rhs)
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
