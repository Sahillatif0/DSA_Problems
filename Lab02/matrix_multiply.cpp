#include<iostream>
#include"matrix_multiply.h"
using namespace std;
int** multiply::mul_arr(int** arr1, int** arr2, int arr1R, int arr1C, int arr2R, int arr2C){
    int** res = new int*[arr1R];
    for(int i=0;i<arr1R;i++)
        res[i] = new int[arr2C];
    if(arr2C!=arr1R)
        return res;
     for (int i = 0; i < arr1R; ++i) 
        for (int j = 0; j < arr2C; ++j) 
            res[i][j] = 0;

    for (int i = 0; i < arr1R; ++i) 
        for (int j = 0; j < arr2C; ++j) 
            for (int k = 0; k < arr1C; ++k) 
                res[i][j] += arr1[i][k] * arr2[k][j];
    return res;
}
void multiply::get_val(){
    cout<<"Hello";
}