#include<iostream>
#include"matrix_multiply.h"
using namespace std;

int main(){
    int arr1R, arr1C, arr2R, arr2C;
    cout<<"Enter rows & cols for arr1: ";
    cin>>arr1R>>arr1C;
    cout<<endl<<"Enter rows & cols for arr2: ";
    cin>>arr2R>>arr2C;
    
    int **arr1 = new int*[arr1R];
    for(int i=0;i<arr1R;i++){
        arr1[i] = new int[arr1C];
        cout<<"Enter arr1 row "<<i+1<<" elements: ";
        for(int j=0;j<arr1C;j++)
            cin>>arr1[i][j];
    }
    int **arr2 = new int*[arr2R];
    for(int i=0;i<arr2R;i++){
        arr2[i] = new int[arr2C];
        cout<<"Enter arr2 row "<<i+1<<" elements: ";
        for(int j=0;j<arr2C;j++)
            cin>>arr1[i][j];
    }
    multiply mm;
    int **res = mm.mul_arr(arr1, arr2, arr1R, arr1C, arr2R, arr2C);
    cout<<"Result Matrix: "<<endl<<endl;
    for(int i=0;i<arr1R;i++){
        for(int j=0;j<arr2C;j++)
            cout<<res[i][j]<<" ";
        cout<<endl;
    }

}