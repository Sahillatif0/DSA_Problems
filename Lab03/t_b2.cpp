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
        void concatenateList(DLL &list){
            Node* temp = head;
            while(temp->next!=NULL)
                temp = temp->next;
            temp->next = list.head;
            list.head->prev = temp;
        }
};

int main() {
    DLL l1, l2;
    l1.insertAtHead(1);
    l1.insertAtHead(2);
    l1.insertAtEnd(3);     
    l1.insertAtEnd(4);
    l1.insertAtPos(5, 2);
    l1.printNodes();
    l2.insertAtHead(3);
    l2.insertAtHead(8);
    l2.insertAtEnd(6);
    l2.insertAtEnd(4);
    l2.insertAtPos(5, 9);
    l2.printNodes();
    l1.concatenateList(l2);
    l1.printNodes();
}