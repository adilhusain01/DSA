#include <bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cout<<"Enter the string : ";
    getline(cin, str);

    stack <char> s;
    for(int i=0; i<str.size(); i++){
        s.push(str[i]);
    }

    cout<<"Original string -> "<<str<<endl;

    for(int i=0; i<str.size(); i++){
        str[i]=s.top();
        s.pop();
    }

    cout<<"Reversed string -> "<<str<<endl;

    return 0;
}