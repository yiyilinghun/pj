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
        bool    c2sRegister     (Login xParam, out int count, out Login ret);
        bool    c2sLogin        (Login xParam, out int count);
    };
};

