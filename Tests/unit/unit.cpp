#include <iostream>
#include <vector>
#include <fstream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "matrix.hpp"

//================================================================================//

TEST(copy_assignment, copy_assignment)
{
    std::vector<int> data{};

    for (int i = 0; i < 4; i++)
        data.push_back(i);

    MatrixSpace::Matrix<int> matrix(2, 2, data.begin(), data.end());

    MatrixSpace::Matrix<int> nmatr(2,2,1);

    nmatr = matrix;

    ASSERT_EQ(nmatr.GetRows(), matrix.GetRows());

    ASSERT_EQ(nmatr.GetCols(), matrix.GetCols());
}

//================================================================================//

TEST(matrix_increasing, matrix_increasing)
{
    using namespace MatrixSpace;

    Matrix<int> m1(2,2,2);

    Matrix<int> m2(3,3,3);

    m1 = m2;

    ASSERT_DOUBLE_EQ(m1.GetRows(), m2.GetRows());

    ASSERT_DOUBLE_EQ(m1.GetCols(), m2.GetCols());
}

//================================================================================//

TEST(operator_test, operator_test)
{
    using namespace MatrixSpace;

    std::vector<int> data{};

    for (int i = 0; i < 4; i++)
        data.push_back(i);

    Matrix<int> m1(2,2, data.begin(), data.end());

    ASSERT_EQ(0, m1[0][0]);

    ASSERT_EQ(1, m1[0][1]);

    ASSERT_EQ(2, m1[1][0]);

    ASSERT_EQ(3, m1[1][1]);
}

//================================================================================//

TEST(max_in_column, max_in_column)
{
    using namespace MatrixSpace;

    std::vector<int> data{};

    for (int i = 1; i <= 9; i++)
        data.push_back(i);

    Matrix<int> m(3, 3, data.begin(), data.end());

    std::pair<size_t, size_t> max[3] = {};

    for (int i = 0; i < 3; i++)
        max[i] = m.GetMaxInColumn(i);

    ASSERT_EQ(7, m[max[0].first][max[0].second]);

    ASSERT_EQ(8, m[max[1].first][max[1].second]);

    ASSERT_EQ(9, m[max[2].first][max[2].second]);
}

//================================================================================//

TEST(max_in_column_negate, max_in_column_negate)
{
    using namespace MatrixSpace;

    std::vector<int> data{};

    data.push_back(0);

    data.push_back(0);

    data.push_back(-1);

    data.push_back(-2);

    Matrix<int> m(2, 2, data.begin(), data.end());

    std::pair<size_t, size_t> max[2] = {};

    for (int i = 0; i < 2; i++)
        max[i] = m.GetMaxInColumn(i);

    ASSERT_EQ(-1, m[max[0].first][max[0].second]);

    ASSERT_EQ(-2, m[max[1].first][max[1].second]);
}

//================================================================================//

TEST(swap_row_test, swap_row_test)
{
    using namespace MatrixSpace;

    std::vector<int> data{};

    for (int i = 1; i <= 4; i++)
        data.push_back(i);

    Matrix<int> m(2, 2, data.begin(), data.end());

    size_t row1 = 0, row2 = 1;

    m.SwapRows(row1, row2);

    ASSERT_EQ(m[0][0], 3);

    ASSERT_EQ(m[0][1], 4);

    ASSERT_EQ(m[1][0], 1);

    ASSERT_EQ(m[1][1], 2);
}

//================================================================================//

TEST(triangle_matrix_determinant, triangle_matrix_determinant)
{
    using namespace MatrixSpace;

    std::vector<int> data{3,10,11,0,5,12,0,0,2};

    Matrix<int> m(3,3, data.begin(), data.end());

    ASSERT_EQ(30, m.Determinant());
}

// //================================================================================//

TEST(gauss_test, gauss_test)
{
    using namespace MatrixSpace;

    std::vector<double> data{3,4,5,3,5,9,6,10,3};

    Matrix<double> m1(3, 3, data.begin(), data.end());

    int det = m1.Determinant();

    ASSERT_EQ(-45, det);
}

//================================================================================//

void EteTestRunner(const char* src, const char* ans)
{
    std::ifstream test_file{};

    test_file.open(src);

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

    test_file.close();

    MatrixSpace::Matrix<double> matrix(size, size, data.begin(), data.end());

    // matrix.Dump();

    double det = matrix.Determinant();

    std::ifstream ans_file{};

    ans_file.open(ans);

    double answ = 0;

    ans_file >> answ;

    ans_file.close();

    // ASSERT_EQ(det, answ);

    ASSERT_EQ(DoubleNumbers::IsEqual(det, answ), true);
}

//================================================================================//

TEST(EteTest, test1)
{
    EteTestRunner("../../../tests/ete/001.dat", "../../../tests/ete/001.answer");
}

//================================================================================//


TEST(EteTest, test2)
{
    EteTestRunner("../../../tests/ete/002.dat", "../../../tests/ete/002.answer");
}

//================================================================================//

TEST(EteTest, test3)
{
    EteTestRunner("../../../tests/ete/003.dat", "../../../tests/ete/003.answer");
}

//================================================================================//

TEST(EteTest, test4)
{
    EteTestRunner("../../../tests/ete/004.dat", "../../../tests/ete/004.answer");
}

//================================================================================//

TEST(EteTest, test5)
{
    EteTestRunner("../../../tests/ete/005.dat", "../../../tests/ete/005.answer");
}

//================================================================================//

TEST(EteTest, test6)
{
    EteTestRunner("../../../tests/ete/006.dat", "../../../tests/ete/006.answer");
}

//================================================================================//

TEST(EteTest, test7)
{
    EteTestRunner("../../../tests/ete/007.dat", "../../../tests/ete/007.answer");
}

//================================================================================//

TEST(EteTest, test8)
{
    EteTestRunner("../../../tests/ete/008.dat", "../../../tests/ete/008.answer");
}

//================================================================================//

TEST(EteTest, test9)
{
    EteTestRunner("../../../tests/ete/009.dat", "../../../tests/ete/009.answer");
}

//================================================================================//

TEST(EteTest, test10)
{
    EteTestRunner("../../../tests/ete/010.dat", "../../../tests/ete/010.answer");
}

//================================================================================//

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

//================================================================================//