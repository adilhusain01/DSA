#include <iostream>
using namespace std;

class queue{
    int *arr;
    int size;
    int top;

    public:
    queue(int size){
        arr=new int[size];
        top=-1;
        this->size=size;
    }

    void insertAtFront(int val){
        if(top>=size){
            cout<<"Can't push, queue is full"<<endl;
        } else {
            int temp[size];
            int i=0;
            while(top!=-1){
                temp[i++]=arr[top--];
            }
            temp[++i]=val;
            while(i!=-1){

            }
        }
    }
}

int main(){
    queue q(5);
}