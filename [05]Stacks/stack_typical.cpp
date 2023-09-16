#include <iostream>
#include <stack>

using namespace std;

int main(){

    //Creation
    stack <int> s;

    //Element Insertion
    s.push(10);
    s.push(20);

    //Varibale data Insertion
    int x=30;
    s.push(x);

    //Getting Stack no of elements
    cout<<"Size is -> "<<s.size()<<endl;

    //Printing data using Top and removing it using Pop
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }

    //Checking if empty or not
    if(s.empty()) cout<< "Empty"<<endl;
    else cout<<"Not Empty"<<endl;

    return 0;
}