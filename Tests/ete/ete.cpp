#include "double_numbers.hpp"
#include "matrix.hpp"

#include <ctime>
#include <fstream>
#include <vector>

//================================================================================//

int main(int argc, char** argv)
{
    std::ifstream test_file{};

    test_file.open(argv[1]);

    size_t size = 0;

    test_file >> size;

    std::vector<double> data{};

    size_t input_size = size * size;

    double elem = 0;

    for (size_t i = 0; i < input_size; i++)
    {
        test_file >> elem;

        data.push_back(elem);
    }

    MatrixSpace::Matrix<double> matrix(size, size, data.begin(), data.end());

    std::clock_t start = clock();

    std::cout << matrix.Determinant() << std::endl;

    std::cout << "Total time is " << double (clock() - start) / CLOCKS_PER_SEC << std::endl;

    test_file.close();

    return 0;
}

//================================================================================//