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
// Generated from file `DB.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

#ifndef __Freeze_DB_h__
#define __Freeze_DB_h__

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

using Key = ::std::vector<::Ice::Byte>;

using Value = ::std::vector<::Ice::Byte>;

}

#else // C++98 mapping

namespace Freeze
{

typedef ::std::vector< ::Ice::Byte> Key;

typedef ::std::vector< ::Ice::Byte> Value;

}

#endif

#include <IceUtil/PopDisableWarnings.h>
#endif
