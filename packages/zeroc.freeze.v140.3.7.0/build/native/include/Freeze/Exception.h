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
// Generated from file `Exception.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

#ifndef __Freeze_Exception_h__
#define __Freeze_Exception_h__

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

class Transaction;

}

namespace Freeze
{

class ICE_CLASS(FREEZE_API) DatabaseException : public ::Ice::LocalExceptionHelper<DatabaseException, ::Ice::LocalException>
{
public:

    ICE_MEMBER(FREEZE_API) virtual ~DatabaseException();

    DatabaseException(const DatabaseException&) = default;

    DatabaseException(const char* file_, int line_) : ::Ice::LocalExceptionHelper<DatabaseException, ::Ice::LocalException>(file_, line_)
    {
    }

    DatabaseException(const char* file_, int line_, const ::std::string& iceP_message) : ::Ice::LocalExceptionHelper<DatabaseException, ::Ice::LocalException>(file_, line_),
        message(::std::move(iceP_message))
    {
    }

    std::tuple<const ::std::string&> ice_tuple() const
    {
        return std::tie(message);
    }

    ICE_MEMBER(FREEZE_API) static const ::std::string& ice_staticId();
    ICE_MEMBER(FREEZE_API) virtual void ice_print(::std::ostream&) const override;

    ::std::string message;
};

class ICE_CLASS(FREEZE_API) NotFoundException : public ::Ice::LocalExceptionHelper<NotFoundException, ::Freeze::DatabaseException>
{
public:

    ICE_MEMBER(FREEZE_API) virtual ~NotFoundException();

    NotFoundException(const NotFoundException&) = default;

    NotFoundException(const char* file_, int line_) : ::Ice::LocalExceptionHelper<NotFoundException, ::Freeze::DatabaseException>(file_, line_)
    {
    }

    NotFoundException(const char* file_, int line_, const ::std::string& iceP_message) :
        ::Ice::LocalExceptionHelper<NotFoundException, ::Freeze::DatabaseException>(file_, line_, ::std::move(iceP_message))
    {
    }

    std::tuple<const ::std::string&> ice_tuple() const
    {
        return std::tie(message);
    }

    ICE_MEMBER(FREEZE_API) static const ::std::string& ice_staticId();
    ICE_MEMBER(FREEZE_API) virtual void ice_print(::std::ostream&) const override;
};

class ICE_CLASS(FREEZE_API) DeadlockException : public ::Ice::LocalExceptionHelper<DeadlockException, ::Freeze::DatabaseException>
{
public:

    ICE_MEMBER(FREEZE_API) virtual ~DeadlockException();

    DeadlockException(const DeadlockException&) = default;

    DeadlockException(const char* file_, int line_) : ::Ice::LocalExceptionHelper<DeadlockException, ::Freeze::DatabaseException>(file_, line_)
    {
    }

    DeadlockException(const char* file_, int line_, const ::std::string& iceP_message, const ::std::shared_ptr<::Freeze::Transaction>& iceP_tx) :
        ::Ice::LocalExceptionHelper<DeadlockException, ::Freeze::DatabaseException>(file_, line_, ::std::move(iceP_message)),
        tx(::std::move(iceP_tx))
    {
    }

    std::tuple<const ::std::string&, const ::std::shared_ptr<::Freeze::Transaction>&> ice_tuple() const
    {
        return std::tie(message, tx);
    }

    ICE_MEMBER(FREEZE_API) static const ::std::string& ice_staticId();
    ICE_MEMBER(FREEZE_API) virtual void ice_print(::std::ostream&) const override;

    ::std::shared_ptr<::Freeze::Transaction> tx;
};

class ICE_CLASS(FREEZE_API) InvalidPositionException : public ::Ice::LocalExceptionHelper<InvalidPositionException, ::Ice::LocalException>
{
public:

    ICE_MEMBER(FREEZE_API) virtual ~InvalidPositionException();

    InvalidPositionException(const InvalidPositionException&) = default;

    InvalidPositionException(const char* file_, int line_) : ::Ice::LocalExceptionHelper<InvalidPositionException, ::Ice::LocalException>(file_, line_)
    {
    }

    std::tuple<> ice_tuple() const
    {
        return std::tie();
    }

    ICE_MEMBER(FREEZE_API) static const ::std::string& ice_staticId();
};

class ICE_CLASS(FREEZE_API) IndexNotFoundException : public ::Ice::LocalExceptionHelper<IndexNotFoundException, ::Ice::LocalException>
{
public:

    ICE_MEMBER(FREEZE_API) virtual ~IndexNotFoundException();

    IndexNotFoundException(const IndexNotFoundException&) = default;

    IndexNotFoundException(const char* file_, int line_) : ::Ice::LocalExceptionHelper<IndexNotFoundException, ::Ice::LocalException>(file_, line_)
    {
    }

    IndexNotFoundException(const char* file_, int line_, const ::std::string& iceP_mapName, const ::std::string& iceP_indexName) : ::Ice::LocalExceptionHelper<IndexNotFoundException, ::Ice::LocalException>(file_, line_),
        mapName(::std::move(iceP_mapName)),
        indexName(::std::move(iceP_indexName))
    {
    }

    std::tuple<const ::std::string&, const ::std::string&> ice_tuple() const
    {
        return std::tie(mapName, indexName);
    }

    ICE_MEMBER(FREEZE_API) static const ::std::string& ice_staticId();
    ICE_MEMBER(FREEZE_API) virtual void ice_print(::std::ostream&) const override;

    ::std::string mapName;
    ::std::string indexName;
};

}

namespace Ice
{

}

namespace Freeze
{

using TransactionPtr = ::std::shared_ptr<Transaction>;

}

#else // C++98 mapping

namespace Freeze
{

class Transaction;
FREEZE_API ::Ice::LocalObject* upCast(::Freeze::Transaction*);
typedef ::IceInternal::Handle< ::Freeze::Transaction> TransactionPtr;

}

namespace Freeze
{

class FREEZE_API DatabaseException : public ::Ice::LocalException
{
public:

    DatabaseException(const char*, int);
    DatabaseException(const char*, int, const ::std::string&);
    virtual ~DatabaseException() throw();

    virtual ::std::string ice_id() const;
    virtual void ice_print(::std::ostream&) const;
    virtual DatabaseException* ice_clone() const;
    virtual void ice_throw() const;

    ::std::string message;
};

class FREEZE_API NotFoundException : public ::Freeze::DatabaseException
{
public:

    NotFoundException(const char*, int);
    NotFoundException(const char*, int, const ::std::string&);
    virtual ~NotFoundException() throw();

    virtual ::std::string ice_id() const;
    virtual void ice_print(::std::ostream&) const;
    virtual NotFoundException* ice_clone() const;
    virtual void ice_throw() const;
};

class FREEZE_API DeadlockException : public ::Freeze::DatabaseException
{
public:

    DeadlockException(const char*, int);
    DeadlockException(const char*, int, const ::std::string&, const ::Freeze::TransactionPtr&);
    virtual ~DeadlockException() throw();

    virtual ::std::string ice_id() const;
    virtual void ice_print(::std::ostream&) const;
    virtual DeadlockException* ice_clone() const;
    virtual void ice_throw() const;

    ::Freeze::TransactionPtr tx;
};

class FREEZE_API InvalidPositionException : public ::Ice::LocalException
{
public:

    InvalidPositionException(const char*, int);
    virtual ~InvalidPositionException() throw();

    virtual ::std::string ice_id() const;
    virtual InvalidPositionException* ice_clone() const;
    virtual void ice_throw() const;
};

class FREEZE_API IndexNotFoundException : public ::Ice::LocalException
{
public:

    IndexNotFoundException(const char*, int);
    IndexNotFoundException(const char*, int, const ::std::string&, const ::std::string&);
    virtual ~IndexNotFoundException() throw();

    virtual ::std::string ice_id() const;
    virtual void ice_print(::std::ostream&) const;
    virtual IndexNotFoundException* ice_clone() const;
    virtual void ice_throw() const;

    ::std::string mapName;
    ::std::string indexName;
};

}

namespace Ice
{

}

#endif

#include <IceUtil/PopDisableWarnings.h>
#endif
