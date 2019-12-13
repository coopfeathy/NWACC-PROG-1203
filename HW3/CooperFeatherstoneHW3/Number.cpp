#include <cmath>
#include <iostream>
#include "Number.h"

Number::Number(long n) : number(n) {}

long Number::get() {
    return number;
}

Number Number::stripZeros() {

    // declaring variables
    long n = 0;
    long x = 0;
    long t = number;

    // if there is a negative, remove it
    if (t < 0) t = -t;

    // mathematically remove all zeros
    while (t > 0) {
        int ld = t % 10;
        if (ld != 0) {
            x++;
        }

        n += ld * pow(10, x);

        t /= 10;
    }

    // if there was a negative, add it back
    if (number < 0) n = -n;

    return Number(n);
}

Number Number::reverse() {
    long t = number;
    long n = 0;

    // if there is a negative, remove it
    if (t < 0) t = -t;

    // mathematically reverse all of the numbers
    while (t > 0) {
        int ld = t % 10;
        n = (n * 10) + ld;
        t /= 10;
    }

    // if there was a negative, add it back
    if (number < 0) n = -n;

    return Number(n);
}
