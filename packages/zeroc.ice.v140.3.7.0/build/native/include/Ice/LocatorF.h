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
// Generated from file `LocatorF.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

#ifndef __Ice_LocatorF_h__
#define __Ice_LocatorF_h__

#include <IceUtil/PushDisableWarnings.h>
#include <Ice/ProxyF.h>
#include <Ice/ObjectF.h>
#include <Ice/ValueF.h>
#include <Ice/Exception.h>
#include <Ice/LocalObject.h>
#include <Ice/StreamHelpers.h>
#include <Ice/Comparable.h>
#include <Ice/Proxy.h>
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

class Locator;
class LocatorPrx;
class LocatorRegistry;
class LocatorRegistryPrx;

}

namespace Ice
{

}

namespace Ice
{

using LocatorPtr = ::std::shared_ptr<Locator>;
using LocatorPrxPtr = ::std::shared_ptr<LocatorPrx>;

using LocatorRegistryPtr = ::std::shared_ptr<LocatorRegistry>;
using LocatorRegistryPrxPtr = ::std::shared_ptr<LocatorRegistryPrx>;

}

#else // C++98 mapping

namespace IceProxy
{

namespace Ice
{

class Locator;
ICE_API void _readProxy(::Ice::InputStream*, ::IceInternal::ProxyHandle< ::IceProxy::Ice::Locator>&);
ICE_API ::IceProxy::Ice::Object* upCast(::IceProxy::Ice::Locator*);

class LocatorRegistry;
ICE_API void _readProxy(::Ice::InputStream*, ::IceInternal::ProxyHandle< ::IceProxy::Ice::LocatorRegistry>&);
ICE_API ::IceProxy::Ice::Object* upCast(::IceProxy::Ice::LocatorRegistry*);

}

}

namespace Ice
{

class Locator;
ICE_API ::Ice::Object* upCast(::Ice::Locator*);
typedef ::IceInternal::Handle< ::Ice::Locator> LocatorPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::Ice::Locator> LocatorPrx;
typedef LocatorPrx LocatorPrxPtr;
ICE_API void _icePatchObjectPtr(LocatorPtr&, const ::Ice::ObjectPtr&);

class LocatorRegistry;
ICE_API ::Ice::Object* upCast(::Ice::LocatorRegistry*);
typedef ::IceInternal::Handle< ::Ice::LocatorRegistry> LocatorRegistryPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::Ice::LocatorRegistry> LocatorRegistryPrx;
typedef LocatorRegistryPrx LocatorRegistryPrxPtr;
ICE_API void _icePatchObjectPtr(LocatorRegistryPtr&, const ::Ice::ObjectPtr&);

}

namespace Ice
{

}

#endif

#include <IceUtil/PopDisableWarnings.h>
#endif
