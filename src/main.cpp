#include <vector>

#include "../inc/matrix.hpp"

int main()
{
    using namespace MatrixSpace;

    Matrix<int> m1(2,2,2);

    Matrix<int> m2(3,3,3);

    m1 = m2;

    return 0;
}