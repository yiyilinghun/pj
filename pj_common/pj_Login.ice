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
        bool    p1r0            (string p1);
        bool    p1r1            (string p1, out int r1);
        bool    p1r2            (string p1, out int r1, out int r2);
        bool    c2sRegister     (Login xParam, out int count, out Login ret);
        bool    c2sLogin        (Login xParam, out int count);
        bool    c2sxqCall       (string name, out int age);
    };
};

