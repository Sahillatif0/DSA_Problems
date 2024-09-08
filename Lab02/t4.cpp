#include<iostream>
using namespace std;

int main() {
    float **courses = new float*[4];
    string names[4] = {"SE", "AI", "CS", "DS"};
    int departmentCouseNumber[4];
    for(int i=0;i<4;i++){
        cout<<"Enter the number of courses offered in "<<names[i]<<" Department: ";
        cin>>departmentCouseNumber[i];
        courses[i] = new float[departmentCouseNumber[i]];
        cout<<"Enter your GPA in courses in "<<names[i]<<" Department: ";
        for(int j=0;j<departmentCouseNumber[i];j++)
            cin>>courses[i][j];
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<departmentCouseNumber[i];j++)
            cout<<"Your GPA in course "<< j+1 <<" of "<<names[i]<<" Department is: "<<courses[i][j]<<endl;
    }
    for(int i=0;i<4;i++)
        delete[] courses[i];
    delete[] courses;
}