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
        void swapNodes(int n1, int n2){
            if(n1==n2) return;
            Node* temp = head;
            Node *node1 = NULL,*node2=NULL;
            for(int i=0;temp->next; i++){
                if(i==n1)
                    node1 = temp;
                if(i==n2)
                    node2 = temp;
                temp = temp->next;
            }
            if (!node1 || !node2) return;
            temp = node2;
            if (node1 == head) head = node2;
            else if (node2 == head) head = node1;
            if (node1->prev) node1->prev->next = node2;
            if (node2->prev) node2->prev->next = node1;
            if (node1->next) node1->next->prev = node2;
            if (node2->next) node2->next->prev = node1;
            Node* tempPrev = node1->prev;
            Node* tempNext = node1->next;
            node1->prev = node2->prev;
            node1->next = node2->next;
            node2->prev = tempPrev;
            node2->next = tempNext;
        }
};

int main() {
    DLL d;
    d.insertAtEnd(1);
    d.insertAtEnd(2);
    d.insertAtEnd(3);
    d.insertAtHead(4);
    d.insertAtEnd(5);
    d.insertAtEnd(6);
    d.insertAtHead(7);
    d.insertAtEnd(8);
    d.insertAtEnd(9);
    d.insertAtEnd(10);
    d.printNodes();
    d.swapNodes(2, 5);
    d.printNodes();

}