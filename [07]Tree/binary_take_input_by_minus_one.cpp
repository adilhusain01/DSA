#include <iostream>
using namespace std;

template <typename T>

class BinaryNode{
    public:
    T data;
    BinaryNode* left;
    BinaryNode* right;

    BinaryNode(T data) : data(data), left(NULL), right(NULL) {}

    ~BinaryNode(){
        delete left;
        delete right;
    }
};

BinaryNode<int>* takeinput(){
    int data;
    cout<<"Enter data : ";
    cin>>data;

    if(data==-1) return NULL;

    BinaryNode<int>* root= new BinaryNode<int>(data);
    BinaryNode<int>* leftchild=takeinput();
    BinaryNode<int>* rightchild=takeinput();

    root->left=leftchild;
    root->right=rightchild;

    return root;
}

void printPreOrder(BinaryNode<int>* root){
    if(root==NULL) return;

    cout<<root->data<<" -> ";
    if((root->left)!=NULL){
        cout<<"L : "<<root->left->data;
    } else {
        cout<<"L : "<<"-";
    }

    if((root->right)!=NULL){
        cout<<" R : "<<root->right->data;
    } else {
        cout<<" R : "<<"-";
    }

    cout<<endl;

    printPreOrder(root->left);
    printPreOrder(root->right);
}

int main(){

    BinaryNode<int>* root=takeinput();
    printPreOrder(root);

    return 0;
}