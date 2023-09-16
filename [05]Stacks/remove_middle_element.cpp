#include <bits/stdc++.h>
using namespace std;

void removeMid(stack <int> & s){
    int mid=s.size()/2;
    int temp[mid];
    for(int i=0; i<mid; i++){
        temp[i]=s.top();
        s.pop();
    }
    s.pop();

    for(int i=0; i<mid; i++){
        s.push(temp[mid-i-1]);
    }
}

int main(){
    stack <int> s;
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);

    removeMid(s);

    while(!s.empty()) {
        cout<<s.top()<<endl;
        s.pop();
    }

    return 0;
}