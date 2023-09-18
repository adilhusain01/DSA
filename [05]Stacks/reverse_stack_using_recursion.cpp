#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack <int> & s, int val){
    if(s.empty()){
        s.push(val);
        return;
    }

    int temp=s.top();
    s.pop();
    insertAtBottom(s, val);
    s.push(temp);
}

void reverseStack(stack <int> & s){
    if(s.empty()){
        return;
    }
    
    int temp=s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s, temp);
}

int main(){
    stack <int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    cout<<"Original stack : "<<endl;
    stack <int> temp=s;
    while(!temp.empty()){
        cout<<temp.top()<<endl;
        temp.pop();
    }

    reverseStack(s);

    cout<<"\nReversed stack : "<<endl;
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }

    return 0;
}