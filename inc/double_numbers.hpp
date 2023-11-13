#ifndef DOUBLE_NUMBERS_
#define DOUBLE_NUMBERS_

namespace DoubleNumbers
{
    const double Eps = 0.00001;

    template<typename T>
    inline bool IsEqual(T num1, T num2)
    {
        return (std::abs(num1 - num2) < Eps);
    }
}

#endif