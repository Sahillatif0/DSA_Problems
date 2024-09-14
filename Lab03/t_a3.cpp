#include<iostream>
using namespace std;
class Node {
    public:
        int val;
        Node* next;
        Node():val(0), next(NULL){}
        Node(int v):val(v), next(NULL){}
};
class CLL {
    public:
        Node* head;
        CLL():head(NULL) {}
        void insertAtHead(int v){
            Node* newnode = new Node(v);
            if(head==NULL){
                head = newnode;
                newnode->next = head;
            }
            else{
                Node* temp = head;
                while(temp->next!=head)
                    temp = temp->next;
                newnode->next = head;
                head = newnode;
                temp->next = head;
            }
        }
        void insertAtEnd(int v){
            Node* newnode = new Node(v);
            if(head==NULL){
                head = newnode;
                newnode->next = head;
            }
            else{
                Node* temp = head;
                while(temp->next!=head)
                    temp = temp->next;
                temp->next = newnode;
                newnode->next = head;
            }
        }
        void insertAtPos(int v, int p){
            Node *newnode = new Node(v);
            if(p==0){
                insertAtHead(v);
                return;
            }
            Node* temp = head;
            for(int i=0;(i<p-1) && (temp->next!=head);i++ )
                temp = temp->next;
            if(temp->next==head)
                insertAtEnd(v);
            else{
                newnode->next = temp->next;
                temp->next = newnode;
            }
            
        }
        void printNodes(){
            Node* temp = head;
            while(temp->next!=head){
                cout<<temp->val<<" ";
                temp = temp->next;
            }
            cout<<temp->val<<endl;
        }

};
int main() {
    CLL ll;
    ll.insertAtHead(1);
    ll.insertAtHead(2);
    ll.insertAtHead(3);
    ll.insertAtEnd(4);
    ll.insertAtEnd(5);
    ll.insertAtPos(6,3);
    ll.insertAtPos(9,8);
    ll.printNodes();

}