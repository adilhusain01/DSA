#include <bits/stdc++.h>
using namespace std;

//Method 1
/*
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
*/

//Method2
//Better than above, uses recursive call

void removeMid(stack <int> & s, int count, int size){
    if (count==size/2){
        s.pop();
        return;
    }

    int temp=s.top();
    s.pop();
    removeMid(s, ++count, size);
    s.push(temp);
}

int main(){
    stack <int> s;
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);

    int count=0;

    removeMid(s, count, s.size());

    while(!s.empty()) {
        cout<<s.top()<<endl;
        s.pop();
    }

    return 0;
}