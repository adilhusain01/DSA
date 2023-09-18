#include <bits/stdc++.h>
using namespace std;

void insertAtTop(int val, queue <int> & q){
    if(q.empty()){
        q.push(val);
        return;
    }

    int temp=s.front();
    s.pop();
    insertAtTop(temp, q);
    s.push(temp);

}

void reverse(queue <int> & q){
    if(q.empty()) return;

    int temp=q.front();
    q.pop();
    reverse(q);
    insertAtTop(temp, q);
}

int main(){
    queue <int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    reverse(q);

    return 0;
}