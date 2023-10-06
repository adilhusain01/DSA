#include <iostream>
using namespace std;

int main(){
    int k=2;
    int arr[]={10, -5, 6, -2, 5, 2};

    int z=sizeof(arr)/sizeof(arr[0]);

    for(int i=0; i<z; i++){//for x lines
        for(int j=i; j<z; j++){//for y lines
            if(j==i+1){
                    
            }
            for(int k=i; k<j+1; k++){
                cout<<arr[k]<<" ";
            }
            cout<<endl;
        }
    }
}

//USING QUEUE