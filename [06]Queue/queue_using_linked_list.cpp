#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList{
    Node* head;

    public:
    LinkedList() : head(nullptr) {}

    void insertAtEnd(int val){
        Node* newnode=new Node(val);
        if (head==nullptr) {
            head=newnode;
        } else {
            Node* current=head;
            while(current->next!=nullptr){
                current=current->next;
            }
            current->next=newnode;
        }
    }

    void push(int val){
        insertAtEnd(val);
    }

    void pop(){
        if(head==nullptr){
            cout<<"Can't pop anymore, the queue is empty!"<<endl;
        }
        else{
            cout<<"Popped Element is -> "<<head->data<<endl;
            Node *temp=head;
            head=head->next;
            delete temp;
        }
    }

    void front(){
        if(head==nullptr){
            cout<<"No front, the queue is empty!"<<endl;
        } else {
            cout<<"Front -> "<<head->data<<endl;
        }
    }

    void back(){
        if(head==nullptr){
            cout<<"No back, the queue is empty!"<<endl;
        } else {
            Node* current=head;
            while(current->next!=nullptr) current=current->next;
            cout<<"Back -> "<<current->data<<endl;
        }
    }

    void display(){
        if(head==nullptr) {
            cout<<"Can't display, queue is empty!"<<endl;
        } else {
            Node* current=head;
            cout<<"Queue :: ";
            while(current!=nullptr){
                cout<<current->data<<" ";
                current=current->next;
            }
            cout<<endl;
        }
    }
};

int main(){
    LinkedList l;
    l.push(1);
    l.push(2);
    l.push(3);

    l.display();
    l.front();
    l.back();

    l.pop();
    l.display();

    l.pop();
    l.pop();
    l.pop();

    return 0;
}