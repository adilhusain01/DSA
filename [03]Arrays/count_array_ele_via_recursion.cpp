#include <bits/stdc++.h>

using namespace std;

int count_digits(long num){
    if(num==0){
        return 1;
    } else {
        return 1+count_digits(num/10);
    }
}

int main(){
    long num;
    cout<<"Enter the number : ";
    cin>>num;

    cout<<"Digits in number "<<num<<" are -> "<<count_digits(num)-1<<endl;
}

// - adil husain