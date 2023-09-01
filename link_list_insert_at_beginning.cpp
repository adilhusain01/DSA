#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList{
    private:
    Node* head;

    public:
    LinkedList() : head(nullptr) {}

    void insertAtBeginning(int val){
        Node* newnode=new  Node(val);
        newnode->next=head;
        head=newnode;
    }

    void print(){
        Node* current = head;
        while(current!=nullptr){
            cout<<current->data<<" -> ";
            current=current->next;
        }
        cout<<nullptr<<endl;
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
        mylist.insertAtBeginning(temp);
    }
    
    mylist.print();

    return 0;
}