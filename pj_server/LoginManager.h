#pragma once

class PJ_LoginManager : virtual public MsNet::ILogin
{
public:
    //PJ_LoginManager(Ice::ObjectAdapterPtr xAdapter, Freeze::ConnectionPtr xFreezeConnection);
    PJ_LoginManager(Ice::ObjectAdapterPtr xAdapter, ::std::string name);
    virtual ~PJ_LoginManager() ICE_NOEXCEPT {};

    //DBDictionary<pj_db> m_writeDictData;
    std::vector<DBDictionary<pj_db>*> m_readDictData;

    virtual bool c2sRegister(const ::MsNet::Login&, ::Ice::Int& r0, ::MsNet::Login& r1, const ::Ice::Current&);
    virtual bool c2sLogin(const ::MsNet::Login&, ::Ice::Int& r0, const ::Ice::Current&);

    ::std::string local_Register(::std::string&& account, ::std::string&& password);

    bool local_Login(::std::string&& account, ::std::string&& password, int32_t index);

    int32_t update_count();

    int32_t m_count;
};

