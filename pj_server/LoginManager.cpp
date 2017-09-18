#include "Precompiled.h"
#include "pj_server.h"
#include "LoginManager.h"

PJ_LoginManager::PJ_LoginManager(Ice::ObjectAdapterPtr xAdapter, Freeze::ConnectionPtr xFreezeConnection)
    : m_DictData(xFreezeConnection, "LoginDB")
{
    xAdapter->add(this, Ice::stringToIdentity("PJ"));
}

static int c2sRegister_num = 0;
static int c2sLoginnum = 0;
static Int64 last_time = 0;
::std::string PJ_LoginManager::c2sRegister(const ::MsNet::Login& xParam, const ::Ice::Current& xCurrent)
{
    c2sRegister_num++;

    SYSTEMTIME st;
    ::GetLocalTime(&st);

    Int64 xNow;
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
    if (m_DictData.ContainsKey(xParam.account))
    {
        return u8"ÕËºÅÒÑ¾­´æÔÚ!";
    }

    ::MsDB::Account xAccount;
    xAccount.account = xParam.account;
    xAccount.password = xParam.password;
    xAccount.Info = xParam.Info;
    m_DictData[xParam.account] = xAccount;

    return u8"ÕËºÅ×¢²á³É¹¦!";
}

bool PJ_LoginManager::c2sLogin(const ::MsNet::Login& xParam, const ::Ice::Current& xCurrent)
{
    c2sLoginnum++;
    //if (c2sLoginnum % 1000 == 0)
    //{
    //    printf("c2sRegister:%d  c2sLogin:%d\n", c2sRegister_num, c2sLoginnum);
    //}

    if (!m_DictData.ContainsKey(xParam.account))
    {
        //return "ÕËºÅÃÜÂë´íÎó!";
        //return "ÕËºÅ²»´æÔÚ!";
        return false;
    }

    if (m_DictData[xParam.account].GetValue().account != xParam.account || m_DictData[xParam.account].GetValue().password != xParam.password)
    {
        //return "ÕËºÅÃÜÂë´íÎó!";
        return false;
    }

    //return "ÕËºÅÃÜÂëÕıÈ·!";
    return true;
}
