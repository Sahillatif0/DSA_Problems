#include<iostream>
using namespace std;

int interpolationSearch(int arr[], int n, int x) {
    int low = 0, high = n - 1;

    while (low <= high && x >= arr[low] && x <= arr[high]) {
        if (low == high) {
            if (arr[low] == x) return low;
            return -1;
        }
        int pos = low + ((x - arr[low]) * (high - low)) / (arr[high] - arr[low]);
        if (arr[pos] == x)
            return pos;
        if (arr[pos] < x)
            low = pos + 1;
        else
            high = pos - 1;
    }
    return -1;
}


int main() {
    int n;
    cout << "Enter the number of datasets: ";
    cin >> n;
    int *data = new int[n];
    for(int i=0;i<n;i++){
        cout << "Enter the data of dataset " << i + 1 << ": ";
        cin >> data[i];
    }
    bool ascend = false, sorted = true, uniform = true;
    if(data[0]<data[1])
        ascend = true;
    for(int i=0;i<n-1;i++){
        if(ascend && data[i]>data[i+1])
            sorted = false;
        else if(!ascend && data[i]<data[i+1])
            sorted = false;
    }
    if(!sorted || (sorted && !ascend)){
        for(int i=0;i<n-1;i++)
            for(int j=0;j<n-i-1;j++)
                if(data[j]>data[j+1])
                    swap(data[j],data[j+1]);
    }
    int uniformDiff = data[1]-data[0];
    for(int i=0;i<n-1;i++)
        if((data[i+1]-data[i])!=uniformDiff)
            uniform = false;
    if(!uniform){
        cout<<"Dataset is not uniform"<<endl;
        return 0;
    }
    cout<<"Sorted Dataset:"<<endl;
    for(int i=0;i<n;i++)
        cout<<data[i]<<" ";
    cout<<endl;
    cout<<"Enter the element you want to search: ";
    int x;
    cin>>x;
    int result = interpolationSearch(data, n, x);
    if(result == -1)
        cout << "Element not found" << endl;
    else
        cout << "Element found at position " << result + 1 << endl;
    delete[] data; 
}