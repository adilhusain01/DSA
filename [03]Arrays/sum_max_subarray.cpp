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

    int maxsum=INT_MIN;

    for(int i=0; i<4; i++){
        for(int j=i; j<4; j++){
            int sum=0;
            for(int k=i; k<j+1; k++){
                sum+=arr[k];
            }
            if (maxsum<sum){
                maxsum=sum;
            }
            cout<<"\n";
        }
    }
    cout<<"Maxsum from all subarrays is  : "<<maxsum<<endl;
    return 0;
}