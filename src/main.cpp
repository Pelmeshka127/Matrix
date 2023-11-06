#include <vector>

#include "matrix.hpp"

int main()
{
    std::vector<int> data{};

    for (int i = 0; i < 4; i++)
        data.push_back(i);

    Matrix::Matrix<int> matrix(2, 2, data.begin(), data.end());

    matrix.Dump(std::cout);

    Matrix::Matrix<int> nmatr(2,2,1);

    nmatr = matrix;

    nmatr.Dump(std::cout);

    return 0;
}