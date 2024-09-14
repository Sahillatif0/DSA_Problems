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
    void seperateEvenAOdd(){
        Node* last = head;
        Node* temp = head;
        Node* originalLast = NULL;
        if(!head || !(head->next)) return;
        while(last->next!=NULL)
            last = last->next;
        originalLast = last;
        while(temp->next!=NULL && temp!=originalLast){
            bool shouldBreak=false;
            if(temp==head && temp->val%2){
                last->next = temp;
                head = temp->next;
                last = last->next;
                last->next = NULL;
                temp = head;
            }
            else if(temp->next->val%2){
                if(temp->next==originalLast)
                    shouldBreak=true;
                last->next = temp->next;
                temp->next = temp->next->next;
                last = last->next;
                last->next = NULL;
            }
            else
                temp = temp->next;
            if(shouldBreak)
                break;
        }
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
    ll1.printNodes();
    ll1.seperateEvenAOdd();
    ll1.printNodes();
}