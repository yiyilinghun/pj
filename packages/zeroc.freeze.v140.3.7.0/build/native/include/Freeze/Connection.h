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
// Generated from file `Connection.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

#ifndef __Freeze_Connection_h__
#define __Freeze_Connection_h__

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
#include <Ice/ExceptionHelpers.h>
#include <Freeze/Transaction.h>
#include <Ice/Version.h>
#include <Ice/CommunicatorF.h>
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

#ifndef FREEZE_API
#   if defined(ICE_STATIC_LIBS)
#       define FREEZE_API /**/
#   elif defined(FREEZE_API_EXPORTS)
#       define FREEZE_API ICE_DECLSPEC_EXPORT
#   else
#       define FREEZE_API ICE_DECLSPEC_IMPORT
#   endif
#endif

#ifdef ICE_CPP11_MAPPING // C++11 mapping

namespace Freeze
{

class Connection;

}

namespace Freeze
{

class ICE_CLASS(FREEZE_API) TransactionAlreadyInProgressException : public ::Ice::LocalExceptionHelper<TransactionAlreadyInProgressException, ::Ice::LocalException>
{
public:

    ICE_MEMBER(FREEZE_API) virtual ~TransactionAlreadyInProgressException();

    TransactionAlreadyInProgressException(const TransactionAlreadyInProgressException&) = default;

    TransactionAlreadyInProgressException(const char* file_, int line_) : ::Ice::LocalExceptionHelper<TransactionAlreadyInProgressException, ::Ice::LocalException>(file_, line_)
    {
    }

    std::tuple<> ice_tuple() const
    {
        return std::tie();
    }

    ICE_MEMBER(FREEZE_API) static const ::std::string& ice_staticId();
};

}

namespace Freeze
{

class ICE_CLASS(FREEZE_API) Connection
{
public:

    ICE_MEMBER(FREEZE_API) virtual ~Connection();

    virtual ::std::shared_ptr<::Freeze::Transaction> beginTransaction() = 0;

    virtual ::std::shared_ptr<::Freeze::Transaction> currentTransaction() const = 0;

    virtual void removeMapIndex(const ::std::string&, const ::std::string&) = 0;

    virtual void close() = 0;

    virtual ::std::shared_ptr<::Ice::Communicator> getCommunicator() const = 0;

    virtual ::Ice::EncodingVersion getEncoding() const = 0;

    virtual ::std::string getName() const = 0;
};

}

namespace Ice
{

}

namespace Freeze
{

using ConnectionPtr = ::std::shared_ptr<Connection>;

}

#else // C++98 mapping

namespace Freeze
{

class Connection;
FREEZE_API ::Ice::LocalObject* upCast(::Freeze::Connection*);
typedef ::IceInternal::Handle< ::Freeze::Connection> ConnectionPtr;

}

namespace Freeze
{

class FREEZE_API TransactionAlreadyInProgressException : public ::Ice::LocalException
{
public:

    TransactionAlreadyInProgressException(const char*, int);
    virtual ~TransactionAlreadyInProgressException() throw();

    virtual ::std::string ice_id() const;
    virtual TransactionAlreadyInProgressException* ice_clone() const;
    virtual void ice_throw() const;
};

}

namespace Freeze
{

class FREEZE_API Connection : public virtual ::Ice::LocalObject
{
public:

    typedef ConnectionPtr PointerType;

    virtual ~Connection();

    virtual ::Freeze::TransactionPtr beginTransaction() = 0;

    virtual ::Freeze::TransactionPtr currentTransaction() const = 0;

    virtual void removeMapIndex(const ::std::string&, const ::std::string&) = 0;

    virtual void close() = 0;

    virtual ::Ice::CommunicatorPtr getCommunicator() const = 0;

    virtual ::Ice::EncodingVersion getEncoding() const = 0;

    virtual ::std::string getName() const = 0;
};

inline bool operator==(const Connection& lhs, const Connection& rhs)
{
    return static_cast<const ::Ice::LocalObject&>(lhs) == static_cast<const ::Ice::LocalObject&>(rhs);
}

inline bool operator<(const Connection& lhs, const Connection& rhs)
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
