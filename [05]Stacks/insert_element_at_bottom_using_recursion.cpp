#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack <int> & s ,int val){
    if(!s.empty()){
        int popped=s.top();
        s.pop();
        insertAtBottom(s, val);
        s.push(popped);
    } else {
        s.push(val);
    }
}

int main(){
    stack <int> s;
    s.push(5);
    s.push(4);
    s.push(3);
    s.push                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  sh(1);

    insertAtBottom(s, 6);

    while(!s.empty()) {
        cout<<s.top()<<endl;
        s.pop();
    }

    return 0;
}