#include <bits/stdc++.h>
using namespace std;

//Constraints - No use of loops

void sort(int val, stack <int> & s){
    if(s.empty() || s.top()<val){
        s.push(val);
        return;
    }

    int temp=s.top();
    s.pop();
    sort(val, s);
    s.push(temp);
}

void sorted(stack <int>  & s){
    if(s.empty()){
        return;
    }

    int temp=s.top();
    s.pop();
    sorted(s);
    sort(temp, s);
}

int main(){
    stack <int> s;
    s.push(5);
    s.push(-2);
    s.push(9);
    s.push(-7);
    s.push(3);

    cout<<"Original Stack : "<<endl;
    stack <int> temp=s;
    while(!temp.empty()){
        cout<<temp.top()<<endl;
        temp.pop();
    }

    sorted(s);

    cout<<"\nSorted Stack : "<<endl;
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }

    return 0;
}