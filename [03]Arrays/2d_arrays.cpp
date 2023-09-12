#include <iostream>
using namespace std;

int main(){
    int m,n;
    cout<<"Enter rows  : ";
    cin>>m;

    cout<<"Enter columns  : ";
    cin>>n;

    int  arr[m][n];

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
        cout<<endl;
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            //cout<<arr[i][j];
            cout<<*(*(arr+i)+j)<<"  ";
        }
        cout<<endl;
    }

    return 0;
}