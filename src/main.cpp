#include <vector>

#include "matrix.hpp"
#include "double_numbers.hpp"

int main(int argc, char** argv)
{
    size_t size = 0;

    std::cin >> size;

    std::vector<double> data{};

    size_t input_size = size * size;

    double elem = 0;

    for (size_t i = 0; i < input_size; i++)
    {
        std::cin >> elem;

        data.push_back(elem);
    }

    MatrixSpace::Matrix<double> matrix(size, size, data.begin(), data.end());

    // matrix.Dump();

    std::cout << matrix.Determinant() << std::endl;

    return 0;
}