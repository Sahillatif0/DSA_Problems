#include<iostream>
using namespace std;
class Node{
    public:
        int val;
        Node *prev, *next;
        Node():val(0), prev(NULL), next(NULL){}
        Node(int v):val(v), prev(NULL), next(NULL){}
};
class DLL{
    public:
        Node* head;
        DLL():head(NULL){}
        void insertAtHead(int d){
            Node* newnode = new Node(d);
            if(head==NULL)
                head = newnode;
            else{
                newnode->next = head;
                head->prev = newnode;
                head = newnode;
            }
        }
        void insertAtEnd(int d){
            Node* newnode = new Node(d);
            if(head==NULL)
                head = newnode;
            else{
                Node *temp = head;
                while(temp->next!=NULL)
                    temp = temp->next;
                temp->next = newnode;
                newnode->prev = temp;
            }
        }
        void insertAtPos(int d, int p){
            Node* newnode = new Node(d);
            if(p==0){
                insertAtHead(d);
                return;
            }
            Node *temp = head;
            for(int i=0;i<p-1 && temp->next!=NULL;i++)
                temp = temp->next;
            if(temp->next==NULL)
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
            while(temp!=NULL){
                cout<<temp->val<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
        void deleteAtPos(int p){
            if(!head)
                return;
            if(p==0){
                Node* temp = head;
                if(!(head->next))
                    head = NULL;
                else{
                    head = head->next;
                    head->prev = NULL;
                }
                delete temp;
                return;
            }
            Node* temp = head;
            for(int i=0;i<p && temp->next!=NULL;i++)
                temp = temp->next;
            Node *toDel = temp;
            if(!(temp->next))
                temp->prev->next = NULL;
            else{
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }
            delete toDel;
        }
};
int main() {
    DLL list;
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