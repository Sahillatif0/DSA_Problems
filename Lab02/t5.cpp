#include<iostream>
using namespace std;

int main() {
    string **attendees;
    int rows, *rowCapacity;
    cout<<"Enter the number of rows: ";
    cin>>rows;
    attendees = new string*[rows];
    rowCapacity = new int[rows];
    for(int i=0;i<rows;i++){
        cout<<"Enter the number of attendees in row "<<i+1<<": ";
        cin>>rowCapacity[i];
        attendees[i] = new string[rowCapacity[i]];
        cout<<"Enter the names of attendees in row "<<i+1<<endl;
        for(int j=0;j<rowCapacity[i];j++){
            cout<<"Column "<<j+1<<": ";
            cin>>attendees[i][j];
        }
    }
    for(int i=0;i<rows;i++){
        cout<<"Attendees in row "<<i+1<<": ";
        for(int j=0;j<rowCapacity[i];j++)
            cout<<attendees[i][j]<<", ";
        cout<<endl;
    }
    for(int i=0;i<rows;i++)
        delete[] attendees[i];
    delete[] attendees;

}