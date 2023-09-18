#include <bits/stdc++.h>
using namespace std;

//((a+b)) here first bracket is redundant as they are needless

void checkRedundant(string & str){
    stack <char> s;
    for(int i=0 ; i<str.size(); i++){
        char ch=str[i];
        if (ch=='(' || ch=='*' || ch=='+' || ch=='-' || ch=='/') s.push(ch);
        else if(ch==')'){
            char top=s.top();
            if (top=='*' || top=='-' || top=='+' || top=='/'){
                s.pop();
                if(s.top()=='(') s.pop();
            }
        }
    }

    if(s.empty()) cout<<"The brackets were not redundant"<<endl;
    else cout<<"The brackets were redundant"<<endl;
}

int main(){
    string str;
    cout<<"Enter the input : ";
    cin>>str;

    checkRedundant(str);

    return 0;
}