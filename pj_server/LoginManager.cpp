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
::std::string
PJ_LoginManager::c2sRegister(const ::MsNet::Login& xParam, const ::Ice::Current& xCurrent)
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
        return u8"’À∫≈“—æ≠¥Ê‘⁄!";
    }

    ::MsDB::Account xAccount;
    xAccount.account = xParam.account;
    xAccount.password = xParam.password;
    xAccount.Info = xParam.Info;
    m_DictData[xParam.account] = xAccount;

    return u8"’À∫≈◊¢≤·≥…π¶!";
}

bool
PJ_LoginManager::c2sLogin(const ::MsNet::Login& xParam, const ::Ice::Current& xCurrent)
{
    c2sLoginnum++;
    //if (c2sLoginnum % 1000 == 0)
    //{
    //    printf("c2sRegister:%d  c2sLogin:%d\n", c2sRegister_num, c2sLoginnum);
    //}

    if (!m_DictData.ContainsKey(xParam.account))
    {
        //return "’À∫≈√‹¬Î¥ÌŒÛ!";
        //return "’À∫≈≤ª¥Ê‘⁄!";
        return false;
    }

    if (m_DictData[xParam.account].GetValue().account != xParam.account || m_DictData[xParam.account].GetValue().password != xParam.password)
    {
        //return "’À∫≈√‹¬Î¥ÌŒÛ!";
        return false;
    }

    //return "’À∫≈√‹¬Î’˝»∑!";
    return true;
}


::std::string
PJ_LoginManager::local_Register(::std::string&& account, ::std::string&& password)
{
    //c2sRegister_num++;

    //SYSTEMTIME st;
    //::GetLocalTime(&st);

    //Int64 xNow;
    //::SystemTimeToFileTime(&st, (LPFILETIME)&xNow);
    //if (xNow - last_time > 10000000)
    //{
    //    printf("c2sRegister:%d  c2sLogin:%d\n", c2sRegister_num, c2sLoginnum);
    //    last_time = xNow;
    //    c2sRegister_num = 0;
    //}

    if (m_DictData.ContainsKey(account))
    {
        return u8"’À∫≈“—æ≠¥Ê‘⁄!";
    }

    ::MsDB::Account xAccount;
    xAccount.account = account;
    xAccount.password = password;
    xAccount.Info = u8"";
    m_DictData[account] = xAccount;

    return u8"’À∫≈◊¢≤·≥…π¶!";
}


