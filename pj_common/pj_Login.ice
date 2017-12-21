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
        bool    c2sRegister     (Login p1, out int count, out Login r2);
        bool    c2sLogin        (Login p1, out int count);
        bool    c2sxqCall       (string name, out int age);
    };


    interface ILogin2
    {
        bool    a2p1r0            (string p1);
        bool    a2p1r1            (string p1, out int r1, out int r2);
        bool    a2p1r2            (string p1, out int r1, out int r2,     out    int     r3         );
        bool    a2c2sRegister     (Login p1, out int count, out Login r2);
        bool    a2c2sLogin        (Login p1,Login p2, out int count);
        //bool    a2c2sxqCall       (string name, out int age);
    };

    interface IScene
    {
        bool    a2p1r0            (string p1);
        bool    a2p1r1            (string p1, out int r1, out int r2);
        bool    a2p1r2            (string p1, out int r1, out int r2,     out    int     r3         );
        bool    a2c2sRegister     (Login p1, out int count, out Login r2);
        bool    a2c2sLogin        (Login p1,Login p2, out int count);
        bool    a2c2sxqCall       (string name, out int age);
    };
};
