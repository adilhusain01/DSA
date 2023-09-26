#include <iostream>
using namespace std;

class queue{
    public:

    int *arr;
    int top;
    int size;

    queue(int size){
        arr=new int[size];
        top=-1;
        this->size=size;
    }

    void push(int val){
        if(top-size>=-1){
            cout<<"Can't push, queue is full!"<<endl;
            return;
        }

        arr[++top]=val;
    }

    void pop(){
        if(top<=-1){
            cout<<"Can't pop, queue is empty!"<<endl;
            return;
        }

        cout<<"Popped element is : "<<arr[0]<<endl;
        for(int i=0; i<top; i++){
            arr[i]=arr[i+1];
        }
        --top;
    }

    void front(){
        cout<<"Front -> "<<arr[0]<<endl;
        return;
    }

    void back(){
        cout<<"Back -> "<<arr[top]<<endl;
        return;
    }

    void display(){
        if(top<=-1){
            cout<<"Can't Dsiplay, nothing to show!\n"<<endl;
            return;
        }

        for(int i=0; i<=top; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        return;
    }
};

int main(){
    queue q(5);

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);

    q.display();

    q.front();;
    q.back();

    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();

    return 0;
}