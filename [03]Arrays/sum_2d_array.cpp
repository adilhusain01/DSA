#include <iostream>
using namespace std;

int main(){
    int m,n;
    cout<<"Enter rows  : ";
    cin>>m;

    cout<<"Enter columns  : ";
    cin>>n;

    int  arr[m][n];
    int sum=0;

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
            sum+=arr[i][j];
        }
        cout<<endl;
    }

    cout<<"The sum is : "<<sum<<endl;

    return 0;
}