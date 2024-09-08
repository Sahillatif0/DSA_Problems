#include <iostream>
using namespace std;
int main()
{
    int **arr = new int *[5];
    int* Size = new int[5];
    int i, j, k;
    for (i = 0; i < 5; i++){
        cout << "Row " << i + 1 << " size: ";

        cin >> Size[i];
        arr[i] = new int[Size[i]];
    }
    for (i = 0; i < 5; i++){
        cout<<"Enter row " <<i+1<<" elements: "; 
        for (j = 0; j < Size[i]; j++)
            cin>>*(*(arr + i) + j);
    }
    
    for (i = 0; i < 5; i++)
        for (j = 0; j < Size[i]; j++)
            cout<<"Element at row " <<i+1<<" col "<<j+1 << ": " << *(*(arr + i) + j)<<endl;
    
    arr = (int**) realloc(arr,sizeof(int*)*10);
    Size = (int*) realloc(Size,sizeof(int)*10);
    cout<<"Enter New Rows Coloumns: "<<endl;
    for (i = 5; i < 10; i++){
        cout << "Row " << i + 1 << " size: ";

        cin >> Size[i];
        arr[i] = new int[Size[i]];
    }
    for (i = 5; i < 10; i++){
        cout<<"Enter row " <<i+1<<" elements: ";
        for (j = 0; j < Size[i]; j++)
            cin>>*(*(arr + i) + j);
    }
    
    for (i = 0; i < 10; i++)
        for (j = 0; j < Size[i]; j++)
            cout<<"Element at row " <<i+1<<" col "<<j+1 << ": " << *(*(arr + i) + j)<<endl;
    for(i=0; i<10;i++)
        delete[] arr[i];
    delete arr;
}