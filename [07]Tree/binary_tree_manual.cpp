#include <iostream>
using namespace std;

template <typename T>

class BinaryNode{
    public:
    T data;
    BinaryNode* left;
    BinaryNode* right;

    BinaryNode(T data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

int main() {
    BinaryNode<int>* root=new BinaryNode<int>(1);
    BinaryNode<int>* leftchild= new BinaryNode<int>(2);
    BinaryNode<int>* rightchild= new BinaryNode<int>(3);
 
    root->left=leftchild;
    root->right=rightchild;

    cout<<"Root data -> "<<root->data<<endl;
    cout<<"Left child data -> "<<root->left->data<<endl;
    cout<<"Right child data -> "<<root->right->data<<endl;

    return 0;
}