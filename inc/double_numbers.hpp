#ifndef DOUBLE_NUMBERS_
#define DOUBLE_NUMBERS_

#include <iostream>

namespace DoubleNumbers
{
    const double Eps = 1e-8;

    bool IsEqual(double num1, double num2);

    bool IsEqual(double num1, double num2)
    {
        return (std::abs(num1 - num2) < Eps);
    }
}

#endif