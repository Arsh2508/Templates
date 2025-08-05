#ifndef MULTIDIM_MATRIX_HPP
#define MULTIDIM_MATRIX_HPP

#include <iostream>
#include <vector>

template <typename T, size_t N>
class MultiDimMatrix {
public:
    MultiDimMatrix(size_t _size);
    MultiDimMatrix(size_t _size, const T& val);

    MultiDimMatrix<T, N-1>& operator[](size_t index);
    bool operator==(const MultiDimMatrix<T, N> &other) const;
    bool operator!=(const MultiDimMatrix<T, N> &other) const;

    void fill(const T& val);

private:
    size_t size;
    std::vector<MultiDimMatrix<T, N-1>> matrix;
};


template <typename T>
class MultiDimMatrix<T, 1> {
public:
    MultiDimMatrix(size_t _size);
    MultiDimMatrix(size_t _size, const T& val);

    T& operator[](size_t index);
    bool operator==(const MultiDimMatrix<T, 1> &other) const;
    bool operator!=(const MultiDimMatrix<T, 1> &other) const;

    void fill(const T& val);

private:
    size_t size;
    std::vector<T> matrix;
};

#include "MultiDimMatrix.cpp"
#endif