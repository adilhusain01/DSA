#include <bits/stdc++.h>
using namespace std;

bool validParenthesis(string str){
    stack <char> s;
    for(int i=0; i<str.size(); i++){
        char ch=str[i];

        if(ch=='{' || ch=='(' || ch=='[') s.push(ch);
        else{
            if(!s.empty()) {
                char top=s.top();
                if((ch=='}' && top=='{') || (ch==']' && top=='[') || (ch==')' && top=='(') ) s.pop();
                else return false;
            } else {
                 return false;
            }
        }
    }
    if (s.empty()) return true;
    else return false;
};

//{[()]}
//{([][])()}
//only {[( are inserted into the stack and then top of tthe stack is compared with the current ch eg: } or ) or ] 
//and if it matches it gets popped and if not then its not valid
//Time complexity of -> O(N)
//Space complexity oof -> O(N)

int main(){
    string str;
    cout<<"Enter the parenthesis sequence : ";
    getline(cin, str);

    if (validParenthesis(str)) cout<<"The parenthesis sequence : "<<str<<" is valid"<<endl;    
    else cout<<"The parenthesis sequence : "<<str<<" is invalid"<<endl; 

    return 0;
}



//Revision
/*
bool check(string str){
    stack <char> s;
    for(int i=0; i<str.size(); i++){
        char ch=str[i];
        if(ch=='{' || ch=='(' || ch=='['){
            s.push(ch);
        } else {
            if(!s.empty()){
                char top=s.top();
                if((ch=='}' && top=='{') || (ch==']' && top=='[') || (ch==')' && top=='(')){
                    s.pop();
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }
    }

    if(s.empty()) return true;
    else return false;
}

int main(){
    string str;
    cout<<"Enter the parenthesis : ";
    cin>>str;

    if(check(str)){
        cout<<"Valid!"<<endl;
    } else {
        cout<<"Not valid!"<<endl;
    }

    return 0;
}
*/