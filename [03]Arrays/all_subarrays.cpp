#include <bits/stdc++.h>

using namespace std;

int main(){
    int size;
    cout<<"Enter the size of array : ";
    cin>>size;

    int arr[size];
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }

    int counter=1;
    for(int i=0; i<4; i++){
        for(int j=i; j<4; j++){
            cout<<"subarray "<<counter<<" is : ";
            for(int k=i; k<j+1; k++){
                cout<<arr[k]<<" ";
            }
            cout<<"\n";
            counter++;
        }
    }
    return 0;
}