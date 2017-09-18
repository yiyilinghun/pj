module MsCommon
{
    module Client
    {
        // Definitions here...
    }
    module Server
    {
        // Definitions here...
    }

    struct TimeOfDay
    {
        short hour;     // 0 - 23
        short minute;   // 0 - 59
        short second;   // 0 - 59
    }

    interface IClock
    {
        TimeOfDay getTime();
        void setTime(TimeOfDay time);
    }
}
