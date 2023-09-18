#include <bits/stdc++.h>
using namespace std;

int main(){
    queue <int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout<<"Front -> "<<q.front()<<endl;
    cout<<"Back -> "<<q.back()<<endl<<endl;

    while(!q.empty()){
        cout<<q.front()<<endl;
        q.pop();
    }
    
    return 0;
}