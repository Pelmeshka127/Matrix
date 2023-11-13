#ifndef MATRIX_HPP_
#define MATRIX_HPP_

#include <iostream>
#include <iomanip>

#include "double_numbers.hpp"

namespace MatrixSpace
{

//================================================================================//

template<typename T>
class Matrix
{

//================================================================================//

private:
    
    T* data_     = nullptr;
    
    size_t rows_ = 0;
    
    size_t cols_ = 0;

//================================================================================//

public:

//================================================================================//

    T*      GetData() const { return data_; }

    size_t  GetRows() const { return rows_; }

    size_t  GetCols() const { return cols_; }

//================================================================================//

    Matrix(size_t rows, size_t cols, T val = T{}) : rows_{rows}, cols_{cols} // Constructor
    {
        size_t size = rows_ * cols_;

        if (!size)
            return;

        data_ = new T[size];

        for (size_t i = 0; i < size; i++)
            data_[i] = val;
    }

//================================================================================//

    template<typename It>
    Matrix(size_t rows, size_t cols, It first, It last) : rows_{rows}, cols_{cols} // Constructor
    {
        size_t size = rows_ * cols_;

        if (!size)
            return;

        data_ = new T[size];

        int i = 0;

        for (It it = first; it != last; it++, i++)
            data_[i] = *it;
    }

//================================================================================//

    Matrix(const Matrix& rhs) :       // Copy Constructor
    rows_{rhs.rows_}, cols_{rhs.cols_}
    {
        // std::cout << "Copy Ctor" << std::endl;

        size_t size = rows_ * cols_;

        if (!size)
            return;

        data_ = new T[size];

        std::copy(rhs.data_, rhs.data_ + size, data_);
    }

//================================================================================//

    Matrix(Matrix&& rhs) noexcept       // Move Constructor
    {
        // std::cout << "Move Ctor" << std::endl;

        std::swap(rows_, rhs.rows_);

        std::swap(cols_, rhs.cols_);

        std::swap(data_, rhs.data_);
    }

//================================================================================//

    Matrix& operator=(const Matrix& rhs)    // Copy Assignment
    {
        // std::cout << "Copy Asgn" << std::endl;

        if (this == &rhs)
            return *this;

        Matrix tmp(rhs);

        std::swap(data_, tmp.data_);

        std::swap(rows_, tmp.rows_);

        std::swap(cols_, tmp.cols_);

        return *this;
    }

//================================================================================//

    Matrix& operator=(Matrix&& rhs) noexcept     // Move Assignment
    {
        // std::cout << "Move Asgn" << std::endl;

        if (this == &rhs)
            return *this;

        delete [] data_;

        data_ = rhs.data_;

        rhs.data_ = nullptr;

        std::swap(rows_, rhs.rows_);

        std::swap(cols_, rhs.cols_);

        return *this;
    }

//================================================================================//

    ~Matrix()   // Destructor
    {
        // std::cout << "Destructor" << std::endl;

        delete [] data_;

        rows_ = 0;

        cols_ = 0;
    }

//================================================================================//

    struct ProxyRow
    {
        T* proxy_row_;

        const size_t num_of_cols_ = 0;

        ProxyRow(T* row, const size_t cols) : proxy_row_{row}, num_of_cols_{cols} {}

        T& operator[](size_t n)     { return proxy_row_[n]; }

        const T& operator[](size_t n) const     { return proxy_row_[n]; }
    };

    ProxyRow operator[](size_t n)
    {
        ProxyRow elem(data_ + n * cols_, cols_);

        return elem;
    }

    const ProxyRow operator[](size_t n) const
    {
        ProxyRow elem(data_ + n * cols_, cols_);

        return elem;
    }
    

//================================================================================//

public:

    bool                            IsEqual(const Matrix& other) const;

    T                               DiagonalProduct() const;

    T                               Determinant() const;

    std::pair<size_t, size_t>       GetMaxInColumn(const size_t column) const;

    void                            SwapRows(const size_t row1, const size_t row2);

    T                               GaussAlgotirhm();

    void                            Dump(std::ostream& os = std::cout) const;

//================================================================================//

}; // end of Matrix class

//================================================================================//

template<typename T>
bool Matrix<T>::IsEqual(const Matrix& other) const
{
    size_t size1 = rows_ * cols_, size2 = other.rows_ * other.cols_;

    if (size1 != size2)
        return false;

    for (size_t i = 0; i < size1; i++)
    {
        if (!(DoubleNumbers::IsEqual(data_[i], other.data_[i])))
            return false;
    }

    return true;
}

//================================================================================//

template<typename T>
T Matrix<T>::DiagonalProduct() const
{
    T det = 1;

    for (size_t row = 0, col = 0; row < rows_; row++, col++)
    {
        det *= data_[row * rows_ + col];
    }

    return det;
}

//================================================================================//

template<typename T>
std::pair<size_t, size_t> Matrix<T>::GetMaxInColumn(const size_t col_num) const
{
    std::pair<size_t, size_t> max_elem{col_num, col_num};

    for (size_t row = col_num; row < rows_; row++)
    {
        if ((std::abs(data_[row * rows_ + col_num]) - std::abs(data_[max_elem.first * rows_ + max_elem.second])) > DoubleNumbers::Eps && 
            !DoubleNumbers::IsEqual(data_[row * rows_ + col_num], 0))
        {
            max_elem.first  = row;

            max_elem.second = col_num;
        }

    }

    return max_elem;
}

//================================================================================//

template<typename T>
void Matrix<T>::SwapRows(const size_t row1, const size_t row2)
{
    for (size_t col = 0; col < cols_; col++)
        std::swap(data_[row1 * rows_ + col], data_[row2 * rows_ + col]);
}

//================================================================================//

template<typename T>
T Matrix<T>::GaussAlgotirhm()
{
    Matrix mtrx(*this);

    int sign = 1;

    for (size_t it = 0; it < mtrx.cols_; it++)
    {
        std::pair<size_t, size_t> max_elem = mtrx.GetMaxInColumn(it);

        if (DoubleNumbers::IsEqual(mtrx[max_elem.first][max_elem.second], 0))
            return 0;

        // std::cout << mtrx[it][it] << " and " << mtrx[max_elem.first][max_elem.second] << std::endl;

        // std::cout << it << " and " << max_elem.first << std::endl;

        if (it != max_elem.first)
        {
            // std::cout << "swapping" << std::endl;
            mtrx.SwapRows(it, max_elem.first);

            sign *= -1;

            max_elem.first = it;
        }
    }    

    // mtrx.Dump();

    T det = mtrx.DiagonalProduct() * sign;

    return det;
}

//================================================================================//

template<typename T>
T Matrix<T>::Determinant() const
{
    return GaussAlgotirhm();
}

//================================================================================//

template<typename T>
void Matrix<T>::Dump(std::ostream& os) const
{
    os << "//==========Start Matrix Dump==========//" << std::endl;

    std::cout << "Matrix " << this << std::endl;

    for (size_t row = 0; row < rows_; row++)
    {
        std::cout << "||";

        for (size_t col = 0; col < cols_; col++)
        {
            os << "  " << data_[row * cols_ + col];
        }

        std::cout << "  ||";

        os << std::endl;
    }

    os << "//=============End Matrix Dump==========//" << std::endl;
}

//================================================================================//

} // end of Matrix namespace

#endif