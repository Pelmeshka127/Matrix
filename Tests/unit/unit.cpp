#include <iostream>
#include <vector>
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

TEST(proxy_row_test, proxy_row_test)
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

TEST(simple_determinant, simple_determinant)
{
    using namespace MatrixSpace;

    std::vector<int> data{3,0,0,1};

    Matrix<int> m(2,2, data.begin(), data.end());

    // m.Dump();

    ASSERT_EQ(3, m.DiagonalProduct());
}

//================================================================================//

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

//================================================================================//