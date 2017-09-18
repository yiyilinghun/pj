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
// Generated from file `pj_db.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//


// Freeze types in this file:
// name="pj_db", key="string", value="MsDB::Account"

#ifndef __pj_db_h__
#define __pj_db_h__

#include <IceUtil/PushDisableWarnings.h>
#include <Freeze/Map.h>
#include "pj_database.h"

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

class pj_db : public Freeze::Map< ::std::string, ::MsDB::Account, ::Freeze::MapKeyCodec< ::std::string>, ::Freeze::MapValueCodec< ::MsDB::Account>, Freeze::IceEncodingCompare >
{
public:


    pj_db(const Freeze::ConnectionPtr&, const std::string&, bool = true, const Freeze::IceEncodingCompare& = Freeze::IceEncodingCompare());

    template<class InputIterator>
    pj_db(const Freeze::ConnectionPtr& connection, const std::string& dbName, bool createDb, InputIterator first, InputIterator last, const Freeze::IceEncodingCompare& compare = Freeze::IceEncodingCompare())
        : Freeze::Map< ::std::string, ::MsDB::Account, ::Freeze::MapKeyCodec< ::std::string>, ::Freeze::MapValueCodec< ::MsDB::Account>, Freeze::IceEncodingCompare >(connection, dbName, keyTypeId(), valueTypeId(), createDb, first, last, compare)
    {
    }

    static std::string keyTypeId();
    static std::string valueTypeId();
};

#include <IceUtil/PopDisableWarnings.h>
#endif
