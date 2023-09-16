#include <iostream>
using namespace std;

class stack{
    public:
        int top;
        int n;
        int *arr;

        //behaviour
        stack(int n){
            this->n=n;
            arr=new int[n];
            top=-1;
        }

        void push(int val){
            if(top-n>=-1) cout<<"Stack is full, can't push anymore!"<<endl;
            else {
                arr[++top]=val;
            }
        }

        void pop(){
            if(top<=-1) cout<<"Stack is empty, can't pop anymore!"<<endl;
            else {
                cout<<"Popped element is -> "<<arr[top]<<endl;
                --top;
            }
        }

        void size(){
            cout<<"Size  of stack is -> "<<top+1<<endl;
        }

        bool isEmpty(){
            if(top<=-1) return true;
            else return false;
        }

        void display(){
            if(top>-1 and top<n){
                int temp=top;
                while(temp>-1) cout<<arr[temp--]<<endl;
            }
            else cout<<"Nothing to display"<<endl;
        }
};

int main(){
    stack s1(5);

    //Inserting and checking push and display function
    s1.push(7);
    s1.push(6);
    s1.push(5);
    s1.push(4);
    s1.push(3);
    s1.push(2);
    s1.push(1);

    s1.display();
    cout<<endl;

    //Checking size function
    s1.size();
    cout<<endl;

    //Checking isEmpty function
    s1.isEmpty();
    cout<<endl;

    //Checking pop and display function
    s1.pop();
    s1.display();
    cout<<endl;

    //Checking the test cases
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    cout<<endl;

    //Checking test case for size again
    s1.size();
    
    return 0;
}