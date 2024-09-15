#include<iostream>
using namespace std;
class Node{
    public:
        int val;
        Node *prev, *next;
        Node():val(0), prev(NULL), next(NULL){}
        Node(int v):val(v), prev(NULL), next(NULL){}
};
class CDLL{
    public:
        Node* head;
        CDLL():head(NULL){}
        void insertAtHead(int d){
            Node* newnode = new Node(d);
            if(head==NULL){
                head = newnode;
                newnode->next = head;
                newnode->prev = newnode;
            }
            else{
                newnode->next = head;
                newnode->prev = head->prev;
                head->prev->next = newnode;
                head->prev = newnode;
                head = newnode;
            }
        }
        void insertAtEnd(int d){
            Node* newnode = new Node(d);
            if(head==NULL){
                head = newnode;
                newnode->next = head;
                newnode->prev = newnode;
            }
            else{
                Node *temp = head;
                while(temp->next!=head)
                    temp = temp->next;
                newnode->next = head;
                newnode->prev = temp;
                head->prev = newnode;
                temp->next = newnode;
            }
        }
        void insertAtPos(int d, int p){
            Node* newnode = new Node(d);
            if(p==0){
                insertAtHead(d);
                return;
            }
            Node *temp = head;
            for(int i=0;i<p-1 && temp->next!=head;i++)
                temp = temp->next;
            if(temp->next==head)
                insertAtEnd(d);
            else{
                newnode->next = temp->next;
                newnode->prev = temp;
                temp->next = newnode;
                newnode->next->prev = newnode;
            }
        }
        void printNodes(){
            Node* temp = head;
            while(temp->next!=head){
                cout<<temp->val<<" ";
                temp = temp->next;
            }
            cout<<temp->val<<" continues same..."<<endl;

        }
        void deleteAtPos(int p) {
            if (!head)
                return;
            if (p == 0) {
                Node* temp = head;
                if (head->next == head)
                    head = NULL;
                else {
                    head->prev->next = head->next; 
                    head->next->prev = head->prev;
                    head = head->next;
                }
                delete temp;
                return;
            }
            Node* temp = head;
            for (int i = 0; i < p && temp->next != head; i++) {
                temp = temp->next;
            }
            if (temp == head)
                return;
            Node* toDel = temp;
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;

            delete toDel;
            }
};
int main() {
    CDLL list;
    list.deleteAtPos(0);
    list.insertAtHead(1);
    list.insertAtHead(2);
    list.deleteAtPos(0);
    list.insertAtHead(3);
    list.insertAtEnd(4);
    list.insertAtEnd(5);
    list.insertAtEnd(6);
    list.deleteAtPos(2);
    list.insertAtPos(7, 0);
    list.insertAtPos(8, 3);
    list.deleteAtPos(5);
    list.printNodes();
    return 0;
}