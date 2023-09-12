#include <iostream>
using namespace std;

class Stack{
    static const int n=100;
    int s[n];
    int top;

    public:
        Stack() : top(-1) {}

        void push(int val){
            if (top-n==-1){
                cout<<"Stack is full, can't PUSH"<<endl;
                return;
            } else {
                ++top;
                s[top]=val;
                return;
            }
        }

        void pop(){
            if(top<=-1){
                cout<<"Stack is empty, can't POP"<<endl;
                return;
            } else {
                cout<<"Popped element is -> "<<s[top]<<endl;
                top--;
                return;
            }
        }

        void display(){
            cout<<"Stack elements are : "<<endl;
            for(int i=top; i>=0; i--){
                cout<<s[i]<<endl;
            }
            return;
        }
};

int main() {
    Stack x;

    x.push(10);
    x.push(20);
    x.push(30);

    x.display();
    x.pop();
    x.display();
}

