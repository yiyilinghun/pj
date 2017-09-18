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
// Generated from file `EndpointF.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

#ifndef __Ice_EndpointF_h__
#define __Ice_EndpointF_h__

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

class EndpointInfo;
class IPEndpointInfo;
class TCPEndpointInfo;
class UDPEndpointInfo;
class WSEndpointInfo;
class Endpoint;

}

namespace Ice
{

using EndpointSeq = ::std::vector<::std::shared_ptr<::Ice::Endpoint>>;

}

namespace Ice
{

}

namespace Ice
{

using EndpointInfoPtr = ::std::shared_ptr<EndpointInfo>;

using IPEndpointInfoPtr = ::std::shared_ptr<IPEndpointInfo>;

using TCPEndpointInfoPtr = ::std::shared_ptr<TCPEndpointInfo>;

using UDPEndpointInfoPtr = ::std::shared_ptr<UDPEndpointInfo>;

using WSEndpointInfoPtr = ::std::shared_ptr<WSEndpointInfo>;

using EndpointPtr = ::std::shared_ptr<Endpoint>;

}

#else // C++98 mapping

namespace Ice
{

class EndpointInfo;
ICE_API ::Ice::LocalObject* upCast(::Ice::EndpointInfo*);
typedef ::IceInternal::Handle< ::Ice::EndpointInfo> EndpointInfoPtr;

class IPEndpointInfo;
ICE_API ::Ice::LocalObject* upCast(::Ice::IPEndpointInfo*);
typedef ::IceInternal::Handle< ::Ice::IPEndpointInfo> IPEndpointInfoPtr;

class TCPEndpointInfo;
ICE_API ::Ice::LocalObject* upCast(::Ice::TCPEndpointInfo*);
typedef ::IceInternal::Handle< ::Ice::TCPEndpointInfo> TCPEndpointInfoPtr;

class UDPEndpointInfo;
ICE_API ::Ice::LocalObject* upCast(::Ice::UDPEndpointInfo*);
typedef ::IceInternal::Handle< ::Ice::UDPEndpointInfo> UDPEndpointInfoPtr;

class WSEndpointInfo;
ICE_API ::Ice::LocalObject* upCast(::Ice::WSEndpointInfo*);
typedef ::IceInternal::Handle< ::Ice::WSEndpointInfo> WSEndpointInfoPtr;

class Endpoint;
ICE_API ::Ice::LocalObject* upCast(::Ice::Endpoint*);
typedef ::IceInternal::Handle< ::Ice::Endpoint> EndpointPtr;

}

namespace Ice
{

typedef ::std::vector< ::Ice::EndpointPtr> EndpointSeq;

}

namespace Ice
{

}

#endif

#include <IceUtil/PopDisableWarnings.h>
#endif
