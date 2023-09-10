

#include <bits/stdc++.h>

using namespace std;


//#Model 1 (Not moore's but similar)

//needs presorted array
//direct calculation and without input , it has a  time complexity of O(1) which is constant with size of array
//array ex: [0 0 0 0 1 1 1 1 1 1]

/*
int main(){

    int arr[]={0, 0, 0, 0, 1, 1, 1, 1, 1, 1};
    int size=sizeof(arr)/sizeof(arr[0]);

    int value=arr[size/2];
    int count=0;

    if(arr[size/2]==arr[(size/2)-1] || arr[size/2]==arr[(size/2)+1]){
        int i=size/2+1, j=size/2;

        if(arr[size/2]==arr[(size/2)+1]){
            while(value==arr[i]){
                count+=1;
                i++;
            }
        }
        if(arr[size/2]==arr[(size/2)-1] ){
            while(value==arr[j]){
                count+=1;
                j--;
            }
        }
    }

    if(count>size/2){
        cout<<"Value "<<value<<" is repeated "<<count<<" times and has majority"<<endl;
    } else {
        cout<<"No majority!!"<<endl;
    }

    return 0;
}
*/



//#Model 2 (Moore's actual Algorithm)

//needs presorted array
//direct calculation and without input , it has a  time complexity of O(n) which is efficient than previous one
//array ex: [0 0 0 0 1 1 1 1 1 1]

int main() {
    int arr[]= {0, 0, 0, 0, 1, 1, 1, 1, 1, 1};
    int size=sizeof(arr)/sizeof(arr[0]);

    int count = 1;
    int majorityElement = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] == majorityElement) {
            count++;
        } else {
            count--;
            if (count == 0) {
                majorityElement = arr[i];
                count = 1;
            }
        }
    }

    count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == majorityElement) {
            count++;
        }
    }

    if (count > size / 2) {
        cout << "Value " << majorityElement << " is repeated " << count << " times and has majority." << endl;
    } else {
        cout << "No majority element found." << endl;
    }

    return 0;
}