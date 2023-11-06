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

    Matrix::Matrix<int> matrix(2, 2, data.begin(), data.end());

    Matrix::Matrix<int> nmatr(2,2,1);

    nmatr = matrix;

    ASSERT_EQ(nmatr.GetRows(), matrix.GetRows());

    ASSERT_EQ(nmatr.GetCols(), matrix.GetCols());
}

//================================================================================//

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

//================================================================================//