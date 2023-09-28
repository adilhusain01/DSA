#include <bits/stdc++.h>
using namespace std;

void sortAndMerge(int arr1, int arr2){
    //sort array1
    for(int i=0; i<sizeof(arr1); i++){
        for(int j=0; i<sizeof(arr1)-1; i++){
            int flag=false;
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag=true;
            }
            if(flag==false) break;
        }
    }
}

int main(){
    int size1;
    cout<<"Enter size of Array1 : ";
    cin>>size1;

    int arr1[size1];
    for(int i=0; i<size1; i++){
        cin>>arr1[i];
    }

    int size2;
    cout<<"Enter size of Array2 : ";
    cin>>size2;

    int arr2[size2];
    for(int i=0; i<size2; i++){
        cin>>arr2[i];
    }

    cout<<sortAndMerge(arr1, arr2);

    return 0;
}