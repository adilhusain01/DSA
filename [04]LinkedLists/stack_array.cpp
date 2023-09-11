#include <iostream>
using namespace std;

int stack[100], n=100, top=-1;

void push(int val){
    if (top>=n-1){
        cout<<"\n  ------->  The stack is full!!"<<endl;
    } else {
        ++top;
        stack[top]=val;
    }
}

void pop(){
     if(top<=-1){
        cout<<"\n  ------->  The list is empty!!"<<endl;
     } else {
        cout<<"\n  ------->  The popped element is -> "<<stack[top]<<endl;
        --top;
     }
}

void sizeSt() {
    int size = top + 1;
    if(size==0) cout<<"\n  ------->  Stack is of no size currently"<<endl;
    else cout<<"\n  ------->  Stack is of size "<<size<<" currently"<<endl;
}

void display(){
    cout<<endl;
    if(top>=0){
        cout<<"\n  ------->  Stack elements are : ";
        for(int i=top; i>=0; i--){
            cout<<stack[i]<<" ";
        }
        cout<<endl;
    } else {
        cout<<"\n  ------->  The stack is empty!!"<<endl;
    }
    cout<<endl;
}

int main(){
    int temp, option;

    while(option!=5){
        cout<<"\n  1) Insert an element  "<<endl;
        cout<<"  2) Pop the last element  "<<endl;
        cout<<"  3) Show current stack size  "<<endl;
        cout<<"  4) Display the elements  "<<endl;
        cout<<"  5) Exit  "<<endl;

        cout<<"\nInput option : ";
        cin>>option;

        switch(option){
            case 1:
                cout<<"Enter the element : ";
                cin>>temp;
                push(temp);
                cout<<"\n  -------  Successfully inserted -> "<<temp<<endl;
                break;
            case 2:
                pop();
                break;
            case 3:
                sizeSt();
                break;
            case 4:
                display();
                break;
            case 5:
                cout<<"\n  -------  Exiting........"<<endl;
                break;
            default:
                cout<<"\n  -------  Invalid input!"<<endl;
        }
    }

    return 0;
}