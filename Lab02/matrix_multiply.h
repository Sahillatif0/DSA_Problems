#ifndef MATRIX_MULTIPLY_H
#define MMATRIX_MULTIPLY_H
// matrix_multiply.h
#include<iostream>
using namespace std;
class multiply{
    public: 
        int** mul_arr(int** arr1, int** arr2, int arr1R, int arr1C, int arr2R, int arr2C);
        void get_val();
};
#endif //MATRIX_MULTIPLY_H