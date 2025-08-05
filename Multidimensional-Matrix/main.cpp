#include <iostream>
#include "MultiDimMatrix.hpp"

int main() 
{
    MultiDimMatrix<int, 2> matrix(3, 7);
    std::cout<<matrix[1][1]<<std::endl;

    matrix.fill(9);

    std::cout<<matrix[0][0]<<std::endl;

    MultiDimMatrix<int, 2> matrix2D(4, 9);

    if(matrix == matrix2D) {
        std::cout <<"equal"<<std::endl;
    }
    else {
        std::cout <<"not equal"<<std::endl;
    }

    std::cout << matrix.sum() <<std::endl;

    return 0;
}
