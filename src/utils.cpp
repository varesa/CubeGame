/*
 * Utils.cpp
 *
 * Author: Esa Varemo
 */

#include <stdio.h>
#include <stdarg.h>

#include "utils.h"

int sign(double number) {
    if(number >= 0)
        return 1;
    if(number < 0)
        return -1;
    return 0;
}

void d(const char * format, ...) {
    va_list args;
    va_start(args, format);
    printf(format, args);
    va_end(args);
    fflush(stdout);
}
