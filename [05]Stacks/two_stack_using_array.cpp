#include <iostream>
using namespace std;

class twoStack{
    public:
        int n;
        int top1, top2;
        int *arr;

        twoStack(int n){
            this->n=n;
            top1=-1;
            top2=n;
            arr=new int[n];
        }

        void push1(int val){
            if(top2-top1<=1) cout<<"Stack 1 is full, can't PUSH1 anymore"<<endl;
            else arr[++top1]=val;
        }

        void push2(int val){
            if(top2-top1<=1) cout<<"Stack 2 is full, can't PUSH2 anymore"<<endl;
            else arr[++top2]=val;
        }

        void pop1(){
            if(top1<=-1) cout<<"Stack 1 is empty, can't POP1 anymore"<<endl;
            else {
                cout<<"The popped1 element is -> "<<arr[top1]<<endl;
                --top1;
            }
        }

        void pop2(){
            if(top2>=n) cout<<"Stack 2 is empty, can't POP1 anymore"<<endl;
            else {
                cout<<"The popped2 element is -> "<<arr[top2]<<endl;
                --top2;
            }
        }

        void peak1(){
            if(top1<=-1) cout<<"Stack 1 is empty, can't PEAK1"<<endl;
            else cout<<arr[top1]<<endl;
        }

        void peak2(){
            if(top2>=n) cout<<"Stack 2 is empty, can't PEAK2"<<endl;
            else cout<<arr[top2]<<endl;
        }

        void size1(){
            cout<<"The size of the Stack 1 is -> "<<top1+1<<endl;
        }

        void size2(){
            cout<<"The size of the Stack 2 is -> "<<n-top2<<endl;
        }

        void isEmpty1(){
            if(top1<=-1) cout<<"Yes, Stack 1 is Empty"<<endl;
            else cout<<"No, Stack 1 is not Empty"<<endl;
        }

        void isEmpty2(){
            if(top2>=n) cout<<"Yes, Stack 2 is Empty"<<endl;
            else cout<<"No, Stack 2 is not Empty"<<endl;
        }

        void display1(){
            if(top1<=-1) cout<<"Stack1 is empty, can't display1"<<endl;
            else {
                int temp=top1;
                while(temp>=0) cout<<arr[temp--]<<endl;
            }
        }

        void display2(){
            if(top2>=n) cout<<"Stack2 is empty, can't display2"<<endl;
            else {
                int temp=top2;
                while(temp<=n-1) cout<<arr[temp++]<<endl;
            }
        }
};

int main(){
    twoStack s1(5);

    //Push and display with test cases
    s1.push1(5);
    s1.push1(4);
    s1.push1(3);
    s1.push1(2);
    s1.push1(1);
    s1.push1(0);
    s1.display1();
    cout<<endl;

    //size with test cases
    s1.size1();
    s1.size2();
    cout<<endl;

    //push again for  diff test case
    s1.push2(15);
    s1.display2();
    cout<<endl;

    //peak 
    s1.peak1();
    s1.peak2();
    cout<<endl;

    //isEmpty with test cases
    s1.isEmpty1();
    s1.isEmpty2();
    cout<<endl;

    //pop with test case
    s1.pop1();
    s1.pop2();


    return 0;
}