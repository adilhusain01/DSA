#include <iostream>
using namespace std;


//1.Informal Way (Only structure of Node made, no function and also manual object creation)

// ---> 1) Singly linked list

/*
struct Node{
    int data;
    struct Node* next;
};

int main(){
    struct Node  n1;
    n1.data=10;
    n1.next=NULL;

    struct Node n2;n1.next->next->next->data
    n2.data=20;
    n2.next=NULL;

    struct Node n3;
    n3.data=30;
    n3.next=NULL;

    n1.next=&n2;
    n2.next=&n3;

    cout<<n1.data<<"  "<<n1.next->data<<"  "<<n1.next->next->data<<endl;
}
*/

// ---> b) Doubly linked list

/*
struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};

int main(){
    struct Node n1;
    n1.data=10;
    n1.prev=NULL;
    n1.next=NULL;

    struct Node n2;
    n2.data=20;
    n2.prev=NULL;
    n2.next=NULL;

    struct Node n3;
    n3.data=30;
    n3.prev=NULL;
    n3.next=NULL;

    n1.next=&n2;
    n2.next=&n3;

    n3.prev=&n2;
    n2.prev=&n1;

    cout<<"From start : "<<n1.data<<"  "<<n1.next->data<<"  "<<n1.next->next->data<<endl;
    cout<<"From end : "<<n3.data<<"  "<<n3.prev->data<<"  "<<n3.prev->prev->data<<endl;

    return 0;
}
*/

// ---> c) Cyclic Singly Linked List

/*
struct Node{
    int data;
    struct Node* next;
};

int main() {
    struct Node  n1;
    n1.data=10;
    n1.next=NULL;

    struct Node n2;
    n2.data=20;
    n2.next=NULL;

    struct Node n3;
    n3.data=30;
    n3.next=NULL;

    n1.next=&n2;
    n2.next=&n3;
    n3.next=&n1;

    cout<<n1.data<<"  "<<n1.next->data<<"  "<<n1.next->next->data<<"| Again repeats : "<<n1.next->next->next->data<<endl;
}
*/

// d) Cyclic Doubly Linked List 

/*
struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};

int main(){
    struct Node n1;
    n1.data=10;
    n1.prev=NULL;
    n1.next=NULL;

    struct Node n2;
    n2.data=20;
    n2.prev=NULL;
    n2.next=NULL;

    struct Node n3;
    n3.data=30;
    n3.prev=NULL;
    n3.next=NULL;

    n1.next=&n2;
    n2.next=&n3;
    n3.next=&n1;

    n3.prev=&n2;
    n2.prev=&n1;
    n1.prev=&n3;

    cout<<"From start : "<<n1.data<<"  "<<n1.next->data<<"  "<<n1.next->next->data<<" | Starts again : "<<n1.next->next->next->data<<endl;
    cout<<"From end : "<<n3.data<<"  "<<n3.prev->data<<"  "<<n3.prev->prev->data<<" | Starts again : "<<n3.prev->prev->prev->data<<endl;

    return 0;
}
*/


//2.Formal Way (Structure of Node made, functions and automatic object creation)

// a) Singly Linked List

/*
struct Node{
    int data;
    Node* next;

    Node(int val){
        data=val;
        next=NULL;
    }
};

void insertAtBegin(Node* &head, int val){
    Node* newnode=new Node(val);
    newnode->next=head;
    head=newnode;
}

void print(Node* &head){
    Node* current=head;
    while(current!=NULL){
        cout<<current->data<<"  ";
        current=current->next;
    }
}

int main(){
    Node* head=NULL;    while(current!=NULL){
        cout<<current->data<<"  ";
        current=current->next;
    }

    int size;
    cout<<"Enter size of linked list : ";
    cin>>size;

    for(int i=0; i<size; i++){
        int temp;
        cin>>temp;
        insertAtBegin(head, temp);
    }

    print(head);

    return 0;
}
*/

// b) Doubly Linked List

struct Node{
    Node* prev;
    int data;
    Node* next;

    Node(int val) : prev(NULL), data(val), next(NULL) {}
};

void insertAtBegin(Node* &head, int val) {
    Node* newnode = new Node(val);

    if (head == NULL) {
        head = newnode;
    } else {
        newnode->next = head;
        head->prev = newnode;  // Add this line to update the prev pointer of the current head
        head = newnode;
    }
}

void print(Node* &head){
    Node* current=head;
    while(current->next!=NULL){
        cout<<current->data<<"  ";
        current=current->next;
    }
}

int main(){
    Node* head=NULL;

    int size;
    cout<<"Enter size of linked list : ";
    cin>>size;

    for(int i=0; i<size; i++){
        int temp;
        cin>>temp;
        insertAtBegin(head, temp);
    }

    print(head);
    return 0;
}