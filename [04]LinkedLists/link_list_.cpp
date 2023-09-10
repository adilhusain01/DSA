#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {};
};

class LinkedList{
    Node* head;

    public:
    LinkedList() : head(nullptr) {}
    
    void insertAtBeginning(int val) {
        Node* newnode=new Node(val);
        newnode->next=head;
        head=newnode;

    }

    void insertAtEnd(int val){
        Node* current=head;
        while(current->next!=nullptr){
            current=current->next;
        }

        Node* newnode=new Node(val);
        if(current==nullptr) head=newnode;
        else current->next=newnode;
    }

    void insertAtPosition(int val, int insert_pos){
        Node* newnode=new Node(val);
        if(insert_pos==1){
            newnode->next=head;
            head=newnode;
            return;
        }

        Node* current = head;
        int currentPos=1;
        while(current!=nullptr && currentPos<insert_pos-1){
            current=current->next;
            currentPos++;
        }

        if(current==nullptr){
            current=head;
            while(current->next!=nullptr){
                current=current->next;
            }
        }
        newnode->next=current->next;
        current->next=newnode;
    }

    void deleteBeginningNode(){
        Node* current=head;
        if(current=nullptr){
            cout<<"Can't Delete Beginning Node, List is already Empty"<<endl;
        } else {
        Node *temp=current;
        current=current->next;
        head=current;
        delete temp;
        }

    }

    void deleteEndNode(){ 
        Node* current=head;
        if(head==nullptr){
            cout<<"Can't Delete End Node, List is already Empty"<<endl;
        } else if (current->next==nullptr) {
            
            head=nullptr;
        } else {
            while(current->next->next!= nullptr){
                current=current->next;
            }
            current->next=nullptr;
        }
    }

    void deleteAtPosition(int del_pos){
        if(del_pos==1){
            head=nullptr;
            return;
        }

        Node* current=head;
        int currPos=1;
        while(current!=nullptr && currPos<del_pos-1){
            current=current->next;
            currPos++;
        }
        current->next=current->next->next;
    }

    void display(){
        Node* current=head;
        if(current==nullptr){
            cout<<"Can't Display, List is Empty"<<endl;
        } else {
            while(current!=nullptr){
                cout<<current->data<<" -> ";
                current=current->next;
            }
            cout<<nullptr<<endl;
        }
    }
};

int main(){

    LinkedList l1;
    l1.insertAtBeginning(10);
    l1.insertAtBeginning(20);
    l1.insertAtBeginning(30);
    l1.insertAtBeginning(40);
    l1.insertAtBeginning(50);
    l1.display();
    l1.deleteAtPosition(6);
    l1.display();

    return 0;
}