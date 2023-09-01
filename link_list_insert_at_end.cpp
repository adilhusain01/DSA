#include <iostream>

using namespace std;

class Node{
    public:

    int data;
    Node* next;

    //Node constructor
    Node(int val) : data(val), next(nullptr) {}
};


class LinkedList{
    private:
    Node* head;

    public:

    //List Constructor
    LinkedList() : head(nullptr) {}

    void insertAtEnd(int val){
        Node* newnode=new Node(val);
        if(head==nullptr){
            head=newnode;
            return;
        }
        Node* current=head;
        while(current->next!=nullptr){
            current=current->next;
        }
        current->next=newnode;
    }

    void print(){
        Node* current=head;
        while(current!=nullptr){
            cout<<current->data<<" -> ";
            current=current->next;
        }
        cout<<nullptr;
    }
};

int main(){
    int size;
    cout<<"Enter the amount of data inputs : ";
    cin>>size;

    LinkedList mylist;
    
    for(int i=0; i<size; i++){
        int temp;
        cout<<"Enter data item "<<i+1<<" to insert at beginning : ";
        cin>>temp;
        mylist.insertAtEnd(temp);
    }
    
    mylist.print();

    return 0;
}