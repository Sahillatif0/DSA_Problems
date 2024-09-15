#include<iostream>
using namespace std;

int main() {
    string designation[] = {"CEO", "CTO", "CFO", "VP", "MGR", "EMP"};
    int n;
    cout << "Enter the number of employees: ";
    cin >> n;
    string employees[n];
    int empPr[n] = {0};
    for (int i = 0; i < n; i++) {
        cout << "Enter the designation of employee " << i + 1 << ": ";
        cin >> employees[i];
    }
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < 6; j++) 
            if (employees[i] == designation[j]) {
                empPr[i] = j;
                break;
            }
    for(int i=0;i<n;i++)
        cout<<empPr[i]<<" ";
    for(int i=1;i<n;i++){
        int temp = i;
        for(int j=i-1;j>=0;j--){
            if(empPr[temp]<empPr[j]){
                swap(employees[temp], employees[j]);
                swap(empPr[temp],empPr[j]), temp = j;
            }
            else
                break;
        }
    }
    for (int i = 0; i < n; i++){
        cout << employees[i] << endl;
    }

}