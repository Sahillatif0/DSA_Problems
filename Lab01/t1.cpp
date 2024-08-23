#include<iostream>
using namespace std;

class BankAccount{
    int balance;
    public:
    BankAccount():balance(0){}
    BankAccount(int balance):balance(balance){}
    BankAccount(const BankAccount& other){
        *this = other;
    }
    int getBalance(){
        return balance;
    }
    void deductBalance(int val){
        balance-=val;
    }
};

int main() {
    BankAccount b1;
    cout<<"Balance in bank account 1: "<<b1.getBalance()<<endl;
    BankAccount b2(1000);
    cout<<"Balance in bank account 2: "<<b2.getBalance()<<endl;
    BankAccount b3(b2);
    cout<<"Balance in bank account 3: "<<b3.getBalance()<<endl;
    b3.deductBalance(200);
    cout<<"Balance in bank account 3 after deducting 500: "<<b3.getBalance()<<endl;
    cout<<"Balance in bank account 2: "<<b2.getBalance()<<endl;

}