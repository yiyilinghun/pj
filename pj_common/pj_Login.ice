module MsNet
{
    struct Register
    {
        string  account;
        string  password;
        string  Info;
    };

    struct Login
    {
        string  account;
        string  password;
        string  Info;
    };

    interface ILogin
    {
        string c2sRegister(Login xParam);
        bool c2sLogin(Login xParam);
    };
};
