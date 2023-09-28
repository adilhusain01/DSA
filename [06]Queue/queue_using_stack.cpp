#include <bits/stdc++.h>
using namespace std;

class QueueStack{
    stack <int> q;
    stack <int> temp; 

    public:
    QueueStack(){}

    void push(int val){
        q.push(val);
    }

    void pop(){
        if(q.empty()){
            cout<<"Can't pop, Queue is empty"<<endl;
            return;
        }

        while(!q.empty()){
            temp.push(q.top());
            q.pop();
        }

        cout<<"Popped element is -> "<<temp.top()<<endl;
        temp.pop();

        while(!temp.empty()){
            q.push(temp.top());
            temp.pop();
        }
    }

    void display(){
        if(q.empty()){
            cout<<"Can't Display, Queue is empty"<<endl;
            return;
        }

        stack <int> temp1 = q;
        stack <int> temp2;
        while(!temp1.empty()){
            temp2.push(temp1.top());
            temp1.pop();
        }

        cout<<"Queue :: ";
        while(!temp2.empty()){
            cout<<temp2.top()<<" ";
            temp2.pop();
        }
        cout<<endl;
    }

    void front(){
        if(q.empty()){
            cout<<"No front, Queue is empty"<<endl;
            return;
        }

        while(!q.empty()){
            temp.push(q.top());
            q.pop();
        }

        cout<<"Front -> "<<temp.top()<<endl;

        while(!temp.empty()){
            q.push(temp.top());
            temp.pop();
        }
    }

    void back(){
        if(q.empty()){
            cout<<"No back, Queue is empty"<<endl;
            return;
        }

        cout<<"Back -> "<<q.top()<<endl;
    }
};

int main(){
    QueueStack q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    q.display();

    q.pop();
    q.pop();

    q.front();
    q.back();

    return 0;
}