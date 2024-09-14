#include<iostream>
using namespace std;

class Node{
    public:
        int val;
        Node* next;
        Node(){val=0, next=NULL;}
        Node(int v){val=v, next=NULL;}
};
class SLL{
    public:
    Node* head;
    SLL(){head=NULL;}
    void inserAtHead(int d){
        Node* newnode = new Node(d);
        if(head==NULL)
            head = newnode;
        else{
            newnode->next = head;
            head = newnode;
        }
    }
    void insertAtEnd(int d){
        Node* newnode = new Node(d);
        if(head==NULL)
            head = newnode;
        else{
            Node* temp = head;
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = newnode;
        }
    }
    void printNodes(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
    bool checkPalindrome(){
        SLL newList;
        Node* temp = head;
        while(temp!=NULL){
            newList.inserAtHead(temp->val);
            temp = temp->next;
        }
        Node* temp1 = head;
        Node* temp2 = newList.head;
        while(temp1!=NULL && temp2!=NULL){
            if(temp1->val!=temp2->val){
                return false;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return true;
    }


};
int main() {
    SLL ll1;
    int n;
    cout<<"Enter the number of nodes you want to insert: ";
    cin>>n;
    for(int i=0; i<n; i++){
        int d;
        cout<<"Enter the value of node "<<i+1<<": ";
        cin>>d;
        ll1.insertAtEnd(d);
    }
    if(ll1.checkPalindrome())
        cout<<"The list is a palindrome"<<endl;
    else
        cout<<"The list is not a palindrome"<<endl;
}