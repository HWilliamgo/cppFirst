//
// Created by HWilliam on 2021/10/1.
//
#include <ctime>
#include <cstdlib>
#include "myutils.h"

int randomNum(int range) {
    time_t seed = time(0);
    srand(seed);
    return rand() % range;
}