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
    }

    cout<<"\n --- > The matrix is : \n";
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<arr[i][j];
        }
        cout<<endl;
    }

    cout<<"\n ---> Normal sum is : "<<sum<<endl;

    int maxcol=0, maxcol_pos, maxrow=0, maxrow_pos;

    cout<<endl;
    for(int j=0; j<n; j++){
        int colsum=0;
        for(int i=0; i<m; i++){
            colsum+=arr[i][j];
        }
        if (colsum>maxcol){
            maxcol=colsum;
            maxcol_pos=j;
        }
        cout<<"The "<<j<<"th colsum is : "<<colsum<<endl;
    }

    cout<<endl;
    for(int i=0; i<m; i++){
        int rowsum=0;
        for(int j=0; j<n; j++){
            rowsum+=arr[i][j];
        }
        if (rowsum>maxrow){
            maxrow=rowsum;
            maxrow_pos=i;
        }
        cout<<"The "<<i<<"th rowsum is : "<<rowsum<<endl;
    }

    if(maxcol>maxrow) cout<<"\n ---> The sum of col "<<maxcol_pos<<" is -> "<<maxcol<<" and greatest.\n"<<endl;
    else cout<<"\n ---> The sum of row "<<maxrow_pos<<" is -> "<<maxrow<<" and greatest.\n"<<endl;

    return 0;
}
