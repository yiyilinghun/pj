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
// Generated from file `ServantLocator.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

#ifndef __Ice_ServantLocator_h__
#define __Ice_ServantLocator_h__

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
#include <Ice/ObjectAdapterF.h>
#include <Ice/Current.h>
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

class ServantLocator;

}

namespace Ice
{

class ICE_CLASS(ICE_API) ServantLocator
{
public:

    ICE_MEMBER(ICE_API) virtual ~ServantLocator();

    virtual ::std::shared_ptr<::Ice::Object> locate(const ::Ice::Current&, ::std::shared_ptr<void>&) = 0;

    virtual void finished(const ::Ice::Current&, const ::std::shared_ptr<::Ice::Object>&, const ::std::shared_ptr<void>&) = 0;

    virtual void deactivate(const ::std::string&) = 0;
};

}

namespace Ice
{

}

namespace Ice
{

using ServantLocatorPtr = ::std::shared_ptr<ServantLocator>;

}

#else // C++98 mapping

namespace Ice
{

class ServantLocator;
ICE_API ::Ice::LocalObject* upCast(::Ice::ServantLocator*);
typedef ::IceInternal::Handle< ::Ice::ServantLocator> ServantLocatorPtr;

}

namespace Ice
{

class ICE_API ServantLocator : public virtual ::Ice::LocalObject
{
public:

    typedef ServantLocatorPtr PointerType;

    virtual ~ServantLocator();

    virtual ::Ice::ObjectPtr locate(const ::Ice::Current&, ::Ice::LocalObjectPtr&) = 0;

    virtual void finished(const ::Ice::Current&, const ::Ice::ObjectPtr&, const ::Ice::LocalObjectPtr&) = 0;

    virtual void deactivate(const ::std::string&) = 0;
};

inline bool operator==(const ServantLocator& lhs, const ServantLocator& rhs)
{
    return static_cast<const ::Ice::LocalObject&>(lhs) == static_cast<const ::Ice::LocalObject&>(rhs);
}

inline bool operator<(const ServantLocator& lhs, const ServantLocator& rhs)
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
