#include<iostream>
using namespace std;
int main() {
    bool friends[5][5] = {{false, true, false, true, true}, {true, false, true, false, true}, {false, true, false, false, false}, {true, false, false, false, true}, {true, true, false, true, false}};
    for(int i=0;i<5;i++){
        int cnt=0;
        for(int j=0;j<5;j++)
            if(friends[i][j])
                cnt++;
        if(cnt>1){
            cout<<"people ";
            for(int j=0;j<5;j++)
                if(friends[i][j])
                    cout<<j<<", ";
            cout<<"are common friends with "<<i<<endl;
        }
    }
}