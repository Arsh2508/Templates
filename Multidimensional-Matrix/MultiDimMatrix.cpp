#include "MultiDimMatrix.hpp"

template <typename T, size_t N>
MultiDimMatrix<T, N>::MultiDimMatrix(size_t _size) 
    : size{_size}
    , matrix(_size, MultiDimMatrix<T, N-1> (_size))
{}

template <typename T, size_t N>
MultiDimMatrix<T, N>::MultiDimMatrix(size_t _size, const T& val)
    : size{_size}
    , matrix(_size, MultiDimMatrix<T, N-1> (_size, val))
{}

template <typename T, size_t N>
MultiDimMatrix<T, N-1> &MultiDimMatrix<T, N>::operator[](size_t index)
{
    return matrix[index];
}

template <typename T>
T& MultiDimMatrix<T, 1>::operator[](size_t index)
{
    return matrix[index];
}

template <typename T>
MultiDimMatrix<T, 1>::MultiDimMatrix(size_t _size) : size{_size}, matrix(_size) {}

template <typename T>
MultiDimMatrix<T, 1>::MultiDimMatrix(size_t _size, const T& val) : size{_size}, matrix(_size, val) {}

template <typename T, size_t N>
void MultiDimMatrix<T, N>::fill(const T& val)
{
    for(size_t i = 0; i < size; ++i) {
        matrix[i].fill(val);
    }
}

template <typename T>
void MultiDimMatrix<T, 1>::fill(const T& val)
{
    for(size_t i = 0; i < size; ++i) {
        matrix[i] = val;
    }
}

template <typename T, size_t N>
bool MultiDimMatrix<T, N>::operator==(const MultiDimMatrix<T, N> &other) const
{
    if(size != other.size) {
        return false;
    }

    for(size_t i = 0; i < size; ++i) {
        if(!(matrix[i] == other.matrix[i])){
            return false;
        }
    }
    return true;
}

template <typename T>
bool MultiDimMatrix<T, 1>::operator==(const MultiDimMatrix<T, 1> &other) const 
{   
    return (matrix == other.matrix);
}

template <typename T, size_t N>
bool MultiDimMatrix<T, N>::operator!=(const MultiDimMatrix<T, N> &other) const
{
    return !(matrix == other.matrix);
}

template <typename T>
bool MultiDimMatrix<T, 1>::operator!=(const MultiDimMatrix<T, 1> &other) const
{
    return !(matrix == other.matrix);
}

template <typename T, size_t N>
T MultiDimMatrix<T, N>::min() const
{
    if(size == 0) {
        throw std::runtime_error("Matrix is empy, can not find mimum!");
    }
    T Min = matrix[0].min();
    for (size_t i = 1; i < size; ++i)
    {
        T curr = matrix[i].min();
        if(Min > curr)
        {
            Min = curr;
        }
    }
    return Min;
}

template <typename T>
T MultiDimMatrix<T, 1>::min() const
{
    if(size == 0) {
        throw std::runtime_error("Matrix is empy, can not find mimum!");
    }
    T Min = matrix[0];
    for(size_t i = 1; i < size; ++i) {
        if(Min > matrix[i]) {
            Min = matrix[i];
        }
    }

    return Min;
}


template <typename T, size_t N>
T MultiDimMatrix<T, N>::max() const
{
    if(size == 0) {
        throw std::runtime_error("Matrix is empy, can not find maximum!");
    }

    T Max = matrix[0].max();
    for (size_t i = 1; i < size; ++i)
    {
        T curr = matrix[i].max();
        if(Max < curr)
        {
            Max = curr;
        }
    }
    return Max;
}

template <typename T>
T MultiDimMatrix<T, 1>::max() const
{
    if(size == 0) {
        throw std::runtime_error("Matrix is empy, can not find maximum!");
    }
    T Max = matrix[0];
    for(size_t i = 1; i < size; ++i) {
        if(Max < matrix[i]) {
            Max = matrix[i];
        }
    }

    return Max;
}

template <typename T, size_t N>
T MultiDimMatrix<T, N>::sum() const
{
    if(size == 0) {
        throw std::runtime_error("Can't count sum of empty matrix!");
    }

    T res = matrix[0].sum();
    for(size_t i = 1; i < size; ++i) {
        res += matrix[i].sum();
    }
    return res;
}

template <typename T>
T MultiDimMatrix<T, 1>::sum() const
{
    if(size == 0) {
        throw std::runtime_error("Can't count sum of empty matrix!");
    }
    T res = matrix[0];
    for(size_t i = 1; i < size; ++i) {
        res += matrix[i];
    }
    return res;
}