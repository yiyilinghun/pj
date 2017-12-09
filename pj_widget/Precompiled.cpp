#include "Precompiled.h"

void _msAssertLog(const char *file, DWORD line, const char *func, const char *expr, const char *info, ...)
{
    printf(expr);
}
