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

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

//================================================================================//