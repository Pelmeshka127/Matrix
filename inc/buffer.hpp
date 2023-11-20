#ifndef BUFFER_HPP_
#define BUFFER_HPP_

namespace MatrixSpace
{

//================================================================================//

template<typename T>
void Construct(T* p, const T& rhs)
{
    new (p) T(rhs);
}

template<class T>
void Destroy(T* p) noexcept
{
    p->~T();
}

template<typename Iter>
void Destroy(Iter fst, Iter lst) noexcept
{
    while (fst != lst)
        Destroy(&*fst++);
}

//================================================================================//

template<typename T>
class Buffer
{

//================================================================================//
    
protected:

    T* data_ = nullptr;

    size_t size_ = 0;

//================================================================================//

protected:

    Buffer(const size_t size = 0) :   data_((size == 0) ? nullptr : static_cast<T*>(::operator new (sizeof(T) * size))),
                                size_{size} {} // Constructor

    Buffer(const Buffer& rhs) = delete; // Copy Constructor

    Buffer& operator=(const Buffer& rhs) = delete; // Copy Assignment

    Buffer(Buffer&& rhs) noexcept  // Move Constructor
    {
        std::swap(data_, rhs.data_);

        std::swap(size_, rhs.size_);
    }

    Buffer& operator=(Buffer&& rhs) noexcept // Move Assignment
    {
        if (*this == rhs)
            return *this;

        std::swap(data_, rhs.data_);

        std::swap(size_, rhs.size_);

        return *this;
    }

    ~Buffer()
    {
        Destroy(data_, data_ + size_);
        ::operator delete(data_);
    }

//================================================================================//

}; // end of Buffer class

//================================================================================//

} // end of Matrix namespace

#endif