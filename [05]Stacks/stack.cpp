#include <iostream>
#include <stack>

using namespace std;

int main(){
    stack <int> s;

    s.push(10);
    s.push(20);
    int x=30;
    s.push(x);

    cout<<"Size is ---> "<<s.size()<<endl;
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }

    return 0;
}