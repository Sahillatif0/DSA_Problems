#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of employees: ";
    cin >> n;
    int *employeeIDs = new int[n];
    for(int i=0;i<n;i++){
        cout << "Enter the employee ID of employee " << i + 1 << ": ";
        cin >> employeeIDs[i];
    }
    int myRollNumber = 63;
    int l=0,r=n-1,m, found = 0;
    while(l<=r){
        m = l + (r - l)/2;
        if(employeeIDs[m]==myRollNumber){
            cout<<"Employee found at position "<<m+1<<endl;
            found = 1;
            break;
        }
        else if(employeeIDs[m]<myRollNumber)
            l = m+1;
        else
            r = m-1;
    }
    if(!found){
        cout<<"Employee not found so added at position: "<<l+1<<endl;
        employeeIDs = (int*) realloc(employeeIDs, (n+1)*sizeof(int));
        employeeIDs[n] = myRollNumber;
        for(int i=n;i>l;i--)
            swap(employeeIDs[i],employeeIDs[i-1]);
        n++;
    }
    for(int i=0;i<n;i++)
        cout<<employeeIDs[i]<<" ";

}