#pragma once

class PJ_LoginManager : virtual public MsNet::ILogin
{
public:
    PJ_LoginManager(Ice::ObjectAdapterPtr xAdapter, Freeze::ConnectionPtr xFreezeConnection);
    virtual ~PJ_LoginManager() ICE_NOEXCEPT {};

    DBDictionary<pj_db> m_DictData;


    virtual ::std::string c2sRegister(const ::MsNet::Login&, const ::Ice::Current&);
    virtual bool c2sLogin(const ::MsNet::Login&, const ::Ice::Current&);
};

