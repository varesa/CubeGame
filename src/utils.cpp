/*
 * Utils.cpp
 *
 * Author: Esa Varemo
 */

#include "utils.h"

int sign(double number) {
    if(number >= 0)
        return 1;
    if(number < 0)
        return -1;
}
