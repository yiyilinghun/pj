#include "Precompiled.h"
#include "pj_server.h"
#include "LoginManager.h"

//PJ_LoginManager::PJ_LoginManager(Ice::ObjectAdapterPtr xAdapter, Freeze::ConnectionPtr xFreezeConnection)
//    : m_writeDictData(xFreezeConnection, "LoginDB")
//{
//    xAdapter->add(this, Ice::stringToIdentity("PJ"));
//    for (int32_t i = 0; i < 100; i++)
//    {
//        m_readDictData.push_back(NEW DBDictionary<pj_db>(xFreezeConnection, "LoginDB"));
//    }
//    m_count = m_writeDictData.GetCount();
//}

PJ_LoginManager::PJ_LoginManager(Ice::ObjectAdapterPtr xAdapter, ::std::string name)
//: m_writeDictData(xFreezeConnection, "LoginDB")
{
    xAdapter->add(this, Ice::stringToIdentity(name));
    //for (int32_t i = 0; i < 100; i++)
    //{
    //    m_readDictData.push_back(NEW DBDictionary<pj_db>(xFreezeConnection, "LoginDB"));
    //}
    //m_count = m_writeDictData.GetCount();
}

static int c2sRegister_num = 0;
static int c2sLoginnum = 0;
static int64_t last_time = 0;


bool
PJ_LoginManager::p1r0(const ::std::string&, const ::Ice::Current&)
{

    return true;
}


bool
PJ_LoginManager::p1r1(const ::std::string&, ::Ice::Int&, const ::Ice::Current&)
{

    return true;
}


bool
PJ_LoginManager::p1r2(const ::std::string&, ::Ice::Int&, ::Ice::Int&, const ::Ice::Current&)
{
    return true;
}


bool
PJ_LoginManager::c2sRegister(const ::MsNet::Login& xParam, ::Ice::Int& r0, ::MsNet::Login& ret, const ::Ice::Current& xCurrent)
{
    c2sRegister_num++;
    qDebug(QString(u8"Register%1").arg(c2sRegister_num).toStdString().c_str());

    ret.account = u8"243579081111111111111111111111111111758924375908234759085479082543079845230798254307982570493878945023780924537089";
    ret.password = ret.account + ret.account + ret.account + ret.account;
    ret.Info = ret.password + ret.password + ret.password + ret.password;
    r0 = c2sRegister_num;

    SYSTEMTIME st;
    ::GetLocalTime(&st);

    int64_t xNow;
    ::SystemTimeToFileTime(&st, (LPFILETIME)&xNow);
    if (xNow - last_time > 10000000)
    {
        printf("c2sRegister:%d  c2sLogin:%d\n", c2sRegister_num, c2sLoginnum);
        last_time = xNow;
        c2sRegister_num = 0;
    }

    //if (c2sRegister_num % 1000 == 0)
    //{
    //    printf("c2sRegister:%d  c2sLogin:%d\n", c2sRegister_num, c2sLoginnum);
    //}
    //if (m_writeDictData.ContainsKey(xParam.account))
    //{
    //    return u8"ÕËºÅÒÑ¾­´æÔÚ!";
    //}

    //::MsDB::Account xAccount;
    //xAccount.account = xParam.account;
    //xAccount.password = xParam.password;
    //xAccount.Info = xParam.Info;
    //m_writeDictData.Add(xParam.account, xAccount);

    return u8"ÕËºÅ×¢²á³É¹¦!";
}

bool
PJ_LoginManager::c2sLogin(const ::MsNet::Login& xParam, ::Ice::Int& r0, const ::Ice::Current& xCurrent)
{
    //if (aa)
    //{
    //    MsNet::Login xxParam;
    //    xxParam.account = "1";
    //    xxParam.password = "1";
    //    g_ice_server_app.m_LoginPrx2->begin_c2sLogin(xxParam);
    //}
    //else
    //{
    //    MsNet::Login xxParam;
    //    xxParam.account = "1";
    //    xxParam.password = "1";
    //    g_ice_server_app.m_LoginPrx1->begin_c2sLogin(xxParam);
    //}


    c2sLoginnum++;
    qDebug(QString(u8"c2sLogin%1").arg(c2sLoginnum).toStdString().c_str());
    r0 = c2sLoginnum;
    //if (c2sLoginnum % 1000 == 0)
    //{
    //    printf("c2sRegister:%d  c2sLogin:%d\n", c2sRegister_num, c2sLoginnum);
    //}

    //if (!m_writeDictData.ContainsKey(xParam.account))
    //{
    //    //return "ÕËºÅÃÜÂë´íÎó!";
    //    //return "ÕËºÅ²»´æÔÚ!";
    //    return false;
    //}

    //if (m_writeDictData.GetValue(xParam.account).password != xParam.password)
    //{
    //    //return "ÕËºÅÃÜÂë´íÎó!";
    //    return false;
    //}

    //return "ÕËºÅÃÜÂëÕıÈ·!";
    if (true)
    {
        return true;
    }
    else
    {
        return false;
    }
    return true;
}

bool
PJ_LoginManager::c2sxqCall(const ::std::string& name, ::Ice::Int& age, const ::Ice::Current&)
{
    if (name == u8"Ğ¡çù")
    {
        age = 100;
    }
    else if (name == u8"Ì«Ò»")
    {
        age = 200;
    }
    else if (name == u8"dongdong")
    {
        age = 17;
    }
    else
    {
        age = -1;
    }

    return true;
}


::std::string
PJ_LoginManager::local_Register(::std::string&& account, ::std::string&& password)
{
    //if (m_writeDictData.ContainsKey(account))
    //{
    //    return u8"ÕËºÅÒÑ¾­´æÔÚ!";
    //}

    //::MsDB::Account xAccount;
    //xAccount.account = account;
    //xAccount.password = password;
    //xAccount.Info = u8"";
    //m_writeDictData.Add(account, xAccount);

    return u8"ÕËºÅ×¢²á³É¹¦!";
}


bool
PJ_LoginManager::local_Login(::std::string&& account, ::std::string&& password, int32_t index)
{
    DBDictionary<pj_db>* readDict = m_readDictData[index - 1];
    if (!readDict->ContainsKey(account))
    {
        // "ÕËºÅ²»´æÔÚ!";
        return false;
    }

    if (readDict->GetValue(account).password != password)
    {
        // "ÕËºÅÃÜÂë´íÎó!";
        return false;
    }

    // "ÕËºÅÃÜÂëÕıÈ·!";
    return true;
}

int32_t PJ_LoginManager::update_count()
{
    //m_count = m_writeDictData.GetCount();
    return m_count;
}

