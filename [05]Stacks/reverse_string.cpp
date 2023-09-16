#include <bits/stdc++.h>
using namespace std;

void revString(string & str){
    stack <char> s;
    for(int i=0; i<str.size(); i++){
        s.push(str[i]);
    }

    for(int i=0; i<str.size(); i++){
        str[i]=s.top();
        s.pop();
    }
}

int main(){
    string str;
    cout<<"Enter the string : ";
    getline(cin, str);

    cout<<"Original string -> "<<str<<endl;

    revString(str);
    cout<<"Reversed string -> "<<str<<endl;

    return 0;
}

//Time complexity - O(N)
//Space complecity - O(N)