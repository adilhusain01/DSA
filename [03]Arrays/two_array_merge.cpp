#include <bits/stdc++.h>

using namespace std;

void merge_array(int size1 , int size2, int result[], int arr1[], int arr2[]){         
    for(int i=0; i<(size1+size2); i++){
        if(i<size1) result[i]=arr1[i];
        else result[i]=arr2[i+1-size2];
    }
}

int main(){

    int size1;
    cout<<"Enter size of first array : ";
    cin>>size1;

    int arr1[size1];
    for(int i=0; i<size1; i++){
        cout<<"Enter element "<<i+1<<" : ";
        cin>>arr1[i];
    }

    int size2;
    cout<<"Enter size of second array : ";
    cin>>size2;

    int arr2[size2];
    for(int i=0; i<size2; i++){
        cout<<"Enter element "<<i+1<<" : ";
        cin>>arr2[i];
    }

    int result[size1+size2];

    merge_array(size1, size2, result, arr1, arr2);
    for(int i=0; i<(size1+size2); i++){
        cout<<result[i]<<" ";
    }
    return 0;
}