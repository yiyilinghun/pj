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
// Generated from file `Process.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

#ifndef __Ice_Process_h__
#define __Ice_Process_h__

#include <IceUtil/PushDisableWarnings.h>
#include <Ice/ProxyF.h>
#include <Ice/ObjectF.h>
#include <Ice/ValueF.h>
#include <Ice/Exception.h>
#include <Ice/LocalObject.h>
#include <Ice/StreamHelpers.h>
#include <Ice/Comparable.h>
#include <Ice/Proxy.h>
#include <Ice/Object.h>
#include <Ice/GCObject.h>
#include <Ice/Value.h>
#include <Ice/Incoming.h>
#include <Ice/FactoryTableInit.h>
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

class Process;
class ProcessPrx;

}

namespace Ice
{

class ICE_API Process : public virtual ::Ice::Object
{
public:

    using ProxyType = ProcessPrx;

    virtual bool ice_isA(::std::string, const ::Ice::Current&) const override;
    virtual ::std::vector<::std::string> ice_ids(const ::Ice::Current&) const override;
    virtual ::std::string ice_id(const ::Ice::Current&) const override;

    static const ::std::string& ice_staticId();

    virtual void shutdown(const ::Ice::Current&) = 0;
    bool _iceD_shutdown(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void writeMessage(::std::string, int, const ::Ice::Current&) = 0;
    bool _iceD_writeMessage(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual bool _iceDispatch(::IceInternal::Incoming&, const ::Ice::Current&) override;
};

}

namespace Ice
{

class ICE_CLASS(ICE_API) ProcessPrx : public virtual ::Ice::Proxy<ProcessPrx, ::Ice::ObjectPrx>
{
public:

    void shutdown(const ::Ice::Context& context = Ice::noExplicitContext)
    {
        _makePromiseOutgoing<void>(true, this, &Ice::ProcessPrx::_iceI_shutdown, context).get();
    }

    template<template<typename> class P = ::std::promise>
    auto shutdownAsync(const ::Ice::Context& context = Ice::noExplicitContext)
        -> decltype(::std::declval<P<void>>().get_future())
    {
        return _makePromiseOutgoing<void, P>(false, this, &Ice::ProcessPrx::_iceI_shutdown, context);
    }

    ::std::function<void()>
    shutdownAsync(::std::function<void()> response,
                  ::std::function<void(::std::exception_ptr)> ex = nullptr,
                  ::std::function<void(bool)> sent = nullptr,
                  const ::Ice::Context& context = Ice::noExplicitContext)
    {
        return _makeLamdaOutgoing<void>(response, ex, sent, this, &Ice::ProcessPrx::_iceI_shutdown, context);
    }

    ICE_MEMBER(ICE_API) void _iceI_shutdown(const ::std::shared_ptr<::IceInternal::OutgoingAsyncT<void>>&, const ::Ice::Context&);

    void writeMessage(const ::std::string& iceP_message, int iceP_fd, const ::Ice::Context& context = Ice::noExplicitContext)
    {
        _makePromiseOutgoing<void>(true, this, &Ice::ProcessPrx::_iceI_writeMessage, iceP_message, iceP_fd, context).get();
    }

    template<template<typename> class P = ::std::promise>
    auto writeMessageAsync(const ::std::string& iceP_message, int iceP_fd, const ::Ice::Context& context = Ice::noExplicitContext)
        -> decltype(::std::declval<P<void>>().get_future())
    {
        return _makePromiseOutgoing<void, P>(false, this, &Ice::ProcessPrx::_iceI_writeMessage, iceP_message, iceP_fd, context);
    }

    ::std::function<void()>
    writeMessageAsync(const ::std::string& iceP_message, int iceP_fd,
                      ::std::function<void()> response,
                      ::std::function<void(::std::exception_ptr)> ex = nullptr,
                      ::std::function<void(bool)> sent = nullptr,
                      const ::Ice::Context& context = Ice::noExplicitContext)
    {
        return _makeLamdaOutgoing<void>(response, ex, sent, this, &Ice::ProcessPrx::_iceI_writeMessage, iceP_message, iceP_fd, context);
    }

    ICE_MEMBER(ICE_API) void _iceI_writeMessage(const ::std::shared_ptr<::IceInternal::OutgoingAsyncT<void>>&, const ::std::string&, int, const ::Ice::Context&);

    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();

protected:

    ProcessPrx() = default;
    friend ::std::shared_ptr<ProcessPrx> IceInternal::createProxy<ProcessPrx>();

    ICE_MEMBER(ICE_API) virtual ::std::shared_ptr<::Ice::ObjectPrx> _newInstance() const override;
};

}

namespace Ice
{

}

namespace Ice
{

using ProcessPtr = ::std::shared_ptr<Process>;
using ProcessPrxPtr = ::std::shared_ptr<ProcessPrx>;

}

#else // C++98 mapping

namespace IceProxy
{

namespace Ice
{

class Process;
ICE_API void _readProxy(::Ice::InputStream*, ::IceInternal::ProxyHandle< ::IceProxy::Ice::Process>&);
ICE_API ::IceProxy::Ice::Object* upCast(::IceProxy::Ice::Process*);

}

}

namespace Ice
{

class Process;
ICE_API ::Ice::Object* upCast(::Ice::Process*);
typedef ::IceInternal::Handle< ::Ice::Process> ProcessPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::Ice::Process> ProcessPrx;
typedef ProcessPrx ProcessPrxPtr;
ICE_API void _icePatchObjectPtr(ProcessPtr&, const ::Ice::ObjectPtr&);

}

namespace Ice
{

class Callback_Process_shutdown_Base : public virtual ::IceInternal::CallbackBase { };
typedef ::IceUtil::Handle< Callback_Process_shutdown_Base> Callback_Process_shutdownPtr;

class Callback_Process_writeMessage_Base : public virtual ::IceInternal::CallbackBase { };
typedef ::IceUtil::Handle< Callback_Process_writeMessage_Base> Callback_Process_writeMessagePtr;

}

namespace IceProxy
{

namespace Ice
{

class ICE_CLASS(ICE_API) Process : public virtual ::Ice::Proxy<Process, ::IceProxy::Ice::Object>
{
public:

    ICE_MEMBER(ICE_API) void shutdown(const ::Ice::Context& context = ::Ice::noExplicitContext)
    {
        end_shutdown(_iceI_begin_shutdown(context, ::IceInternal::dummyCallback, 0, true));
    }

    ::Ice::AsyncResultPtr begin_shutdown(const ::Ice::Context& context = ::Ice::noExplicitContext)
    {
        return _iceI_begin_shutdown(context, ::IceInternal::dummyCallback, 0);
    }

    ::Ice::AsyncResultPtr begin_shutdown(const ::Ice::CallbackPtr& del, const ::Ice::LocalObjectPtr& cookie = 0)
    {
        return _iceI_begin_shutdown(::Ice::noExplicitContext, del, cookie);
    }

    ::Ice::AsyncResultPtr begin_shutdown(const ::Ice::Context& context, const ::Ice::CallbackPtr& del, const ::Ice::LocalObjectPtr& cookie = 0)
    {
        return _iceI_begin_shutdown(context, del, cookie);
    }

    ::Ice::AsyncResultPtr begin_shutdown(const ::Ice::Callback_Process_shutdownPtr& del, const ::Ice::LocalObjectPtr& cookie = 0)
    {
        return _iceI_begin_shutdown(::Ice::noExplicitContext, del, cookie);
    }

    ::Ice::AsyncResultPtr begin_shutdown(const ::Ice::Context& context, const ::Ice::Callback_Process_shutdownPtr& del, const ::Ice::LocalObjectPtr& cookie = 0)
    {
        return _iceI_begin_shutdown(context, del, cookie);
    }

    ICE_MEMBER(ICE_API) void end_shutdown(const ::Ice::AsyncResultPtr&);

private:

    ICE_MEMBER(ICE_API) ::Ice::AsyncResultPtr _iceI_begin_shutdown(const ::Ice::Context&, const ::IceInternal::CallbackBasePtr&, const ::Ice::LocalObjectPtr& cookie = 0, bool sync = false);

public:

    ICE_MEMBER(ICE_API) void writeMessage(const ::std::string& iceP_message, ::Ice::Int iceP_fd, const ::Ice::Context& context = ::Ice::noExplicitContext)
    {
        end_writeMessage(_iceI_begin_writeMessage(iceP_message, iceP_fd, context, ::IceInternal::dummyCallback, 0, true));
    }

    ::Ice::AsyncResultPtr begin_writeMessage(const ::std::string& iceP_message, ::Ice::Int iceP_fd, const ::Ice::Context& context = ::Ice::noExplicitContext)
    {
        return _iceI_begin_writeMessage(iceP_message, iceP_fd, context, ::IceInternal::dummyCallback, 0);
    }

    ::Ice::AsyncResultPtr begin_writeMessage(const ::std::string& iceP_message, ::Ice::Int iceP_fd, const ::Ice::CallbackPtr& del, const ::Ice::LocalObjectPtr& cookie = 0)
    {
        return _iceI_begin_writeMessage(iceP_message, iceP_fd, ::Ice::noExplicitContext, del, cookie);
    }

    ::Ice::AsyncResultPtr begin_writeMessage(const ::std::string& iceP_message, ::Ice::Int iceP_fd, const ::Ice::Context& context, const ::Ice::CallbackPtr& del, const ::Ice::LocalObjectPtr& cookie = 0)
    {
        return _iceI_begin_writeMessage(iceP_message, iceP_fd, context, del, cookie);
    }

    ::Ice::AsyncResultPtr begin_writeMessage(const ::std::string& iceP_message, ::Ice::Int iceP_fd, const ::Ice::Callback_Process_writeMessagePtr& del, const ::Ice::LocalObjectPtr& cookie = 0)
    {
        return _iceI_begin_writeMessage(iceP_message, iceP_fd, ::Ice::noExplicitContext, del, cookie);
    }

    ::Ice::AsyncResultPtr begin_writeMessage(const ::std::string& iceP_message, ::Ice::Int iceP_fd, const ::Ice::Context& context, const ::Ice::Callback_Process_writeMessagePtr& del, const ::Ice::LocalObjectPtr& cookie = 0)
    {
        return _iceI_begin_writeMessage(iceP_message, iceP_fd, context, del, cookie);
    }

    ICE_MEMBER(ICE_API) void end_writeMessage(const ::Ice::AsyncResultPtr&);

private:

    ICE_MEMBER(ICE_API) ::Ice::AsyncResultPtr _iceI_begin_writeMessage(const ::std::string&, ::Ice::Int, const ::Ice::Context&, const ::IceInternal::CallbackBasePtr&, const ::Ice::LocalObjectPtr& cookie = 0, bool sync = false);

public:

    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();

protected:

    ICE_MEMBER(ICE_API) virtual ::IceProxy::Ice::Object* _newInstance() const;
};

}

}

namespace Ice
{

class ICE_API Process : public virtual ::Ice::Object
{
public:

    typedef ProcessPrx ProxyType;
    typedef ProcessPtr PointerType;

    virtual ~Process();

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::emptyCurrent) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::emptyCurrent) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::emptyCurrent) const;

    static const ::std::string& ice_staticId();

    virtual void shutdown(const ::Ice::Current& = ::Ice::emptyCurrent) = 0;
    bool _iceD_shutdown(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void writeMessage(const ::std::string&, ::Ice::Int, const ::Ice::Current& = ::Ice::emptyCurrent) = 0;
    bool _iceD_writeMessage(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual bool _iceDispatch(::IceInternal::Incoming&, const ::Ice::Current&);

protected:

    virtual void _iceWriteImpl(::Ice::OutputStream*) const;
    virtual void _iceReadImpl(::Ice::InputStream*);
};

inline bool operator==(const Process& lhs, const Process& rhs)
{
    return static_cast<const ::Ice::Object&>(lhs) == static_cast<const ::Ice::Object&>(rhs);
}

inline bool operator<(const Process& lhs, const Process& rhs)
{
    return static_cast<const ::Ice::Object&>(lhs) < static_cast<const ::Ice::Object&>(rhs);
}

}

namespace Ice
{

}

namespace Ice
{

template<class T>
class CallbackNC_Process_shutdown : public Callback_Process_shutdown_Base, public ::IceInternal::OnewayCallbackNC<T>
{
public:

    typedef IceUtil::Handle<T> TPtr;

    typedef void (T::*Exception)(const ::Ice::Exception&);
    typedef void (T::*Sent)(bool);
    typedef void (T::*Response)();

    CallbackNC_Process_shutdown(const TPtr& obj, Response cb, Exception excb, Sent sentcb)
        : ::IceInternal::OnewayCallbackNC<T>(obj, cb, excb, sentcb)
    {
    }
};

template<class T> Callback_Process_shutdownPtr
newCallback_Process_shutdown(const IceUtil::Handle<T>& instance, void (T::*cb)(), void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_Process_shutdown<T>(instance, cb, excb, sentcb);
}

template<class T> Callback_Process_shutdownPtr
newCallback_Process_shutdown(const IceUtil::Handle<T>& instance, void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_Process_shutdown<T>(instance, 0, excb, sentcb);
}

template<class T> Callback_Process_shutdownPtr
newCallback_Process_shutdown(T* instance, void (T::*cb)(), void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_Process_shutdown<T>(instance, cb, excb, sentcb);
}

template<class T> Callback_Process_shutdownPtr
newCallback_Process_shutdown(T* instance, void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_Process_shutdown<T>(instance, 0, excb, sentcb);
}

template<class T, typename CT>
class Callback_Process_shutdown : public Callback_Process_shutdown_Base, public ::IceInternal::OnewayCallback<T, CT>
{
public:

    typedef IceUtil::Handle<T> TPtr;

    typedef void (T::*Exception)(const ::Ice::Exception& , const CT&);
    typedef void (T::*Sent)(bool , const CT&);
    typedef void (T::*Response)(const CT&);

    Callback_Process_shutdown(const TPtr& obj, Response cb, Exception excb, Sent sentcb)
        : ::IceInternal::OnewayCallback<T, CT>(obj, cb, excb, sentcb)
    {
    }
};

template<class T, typename CT> Callback_Process_shutdownPtr
newCallback_Process_shutdown(const IceUtil::Handle<T>& instance, void (T::*cb)(const CT&), void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_Process_shutdown<T, CT>(instance, cb, excb, sentcb);
}

template<class T, typename CT> Callback_Process_shutdownPtr
newCallback_Process_shutdown(const IceUtil::Handle<T>& instance, void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_Process_shutdown<T, CT>(instance, 0, excb, sentcb);
}

template<class T, typename CT> Callback_Process_shutdownPtr
newCallback_Process_shutdown(T* instance, void (T::*cb)(const CT&), void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_Process_shutdown<T, CT>(instance, cb, excb, sentcb);
}

template<class T, typename CT> Callback_Process_shutdownPtr
newCallback_Process_shutdown(T* instance, void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_Process_shutdown<T, CT>(instance, 0, excb, sentcb);
}

template<class T>
class CallbackNC_Process_writeMessage : public Callback_Process_writeMessage_Base, public ::IceInternal::OnewayCallbackNC<T>
{
public:

    typedef IceUtil::Handle<T> TPtr;

    typedef void (T::*Exception)(const ::Ice::Exception&);
    typedef void (T::*Sent)(bool);
    typedef void (T::*Response)();

    CallbackNC_Process_writeMessage(const TPtr& obj, Response cb, Exception excb, Sent sentcb)
        : ::IceInternal::OnewayCallbackNC<T>(obj, cb, excb, sentcb)
    {
    }
};

template<class T> Callback_Process_writeMessagePtr
newCallback_Process_writeMessage(const IceUtil::Handle<T>& instance, void (T::*cb)(), void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_Process_writeMessage<T>(instance, cb, excb, sentcb);
}

template<class T> Callback_Process_writeMessagePtr
newCallback_Process_writeMessage(const IceUtil::Handle<T>& instance, void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_Process_writeMessage<T>(instance, 0, excb, sentcb);
}

template<class T> Callback_Process_writeMessagePtr
newCallback_Process_writeMessage(T* instance, void (T::*cb)(), void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_Process_writeMessage<T>(instance, cb, excb, sentcb);
}

template<class T> Callback_Process_writeMessagePtr
newCallback_Process_writeMessage(T* instance, void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_Process_writeMessage<T>(instance, 0, excb, sentcb);
}

template<class T, typename CT>
class Callback_Process_writeMessage : public Callback_Process_writeMessage_Base, public ::IceInternal::OnewayCallback<T, CT>
{
public:

    typedef IceUtil::Handle<T> TPtr;

    typedef void (T::*Exception)(const ::Ice::Exception& , const CT&);
    typedef void (T::*Sent)(bool , const CT&);
    typedef void (T::*Response)(const CT&);

    Callback_Process_writeMessage(const TPtr& obj, Response cb, Exception excb, Sent sentcb)
        : ::IceInternal::OnewayCallback<T, CT>(obj, cb, excb, sentcb)
    {
    }
};

template<class T, typename CT> Callback_Process_writeMessagePtr
newCallback_Process_writeMessage(const IceUtil::Handle<T>& instance, void (T::*cb)(const CT&), void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_Process_writeMessage<T, CT>(instance, cb, excb, sentcb);
}

template<class T, typename CT> Callback_Process_writeMessagePtr
newCallback_Process_writeMessage(const IceUtil::Handle<T>& instance, void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_Process_writeMessage<T, CT>(instance, 0, excb, sentcb);
}

template<class T, typename CT> Callback_Process_writeMessagePtr
newCallback_Process_writeMessage(T* instance, void (T::*cb)(const CT&), void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_Process_writeMessage<T, CT>(instance, cb, excb, sentcb);
}

template<class T, typename CT> Callback_Process_writeMessagePtr
newCallback_Process_writeMessage(T* instance, void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_Process_writeMessage<T, CT>(instance, 0, excb, sentcb);
}

}

#endif

#include <IceUtil/PopDisableWarnings.h>
#endif
