#include <iostream>

using namespace std;

//Checks whether array is sorted or not using recursion


bool check_sorted(int size, int arr[], int index){
    if((size==0) || (size==1) || (index==size-1)){
        return true;
    } else {
        if (arr[index]>arr[index+1]) {
            return false;
        }
        else {
            return check_sorted(size, arr, index+1);
        }
    }
    return false;
}

int main(){
    int size;
    cout<<"Enter size : ";
    cin>>size;

    int arr[size];
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }

    if (check_sorted(size, arr, 0)) cout<<"The array provided is sorted."<<endl;
    else cout<<"Not a sorted one"<<endl;
    return 0;
}
