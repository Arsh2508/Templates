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
    for(int i = 0; i < size; ++i) {
        matrix[i].fill(val);
    }
}

template <typename T>
void MultiDimMatrix<T, 1>::fill(const T& val)
{
    for(int i = 0; i < size; ++i) {
        matrix[i] = val;
    }
}

template <typename T, size_t N>
bool MultiDimMatrix<T, N>::operator==(const MultiDimMatrix<T, N> &other) const
{
    if(size != other.size) {
        return false;
    }

    for(int i = 0; i < size; ++i) {
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