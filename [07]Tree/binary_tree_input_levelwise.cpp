#include <bits/stdc++.h>
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

BinaryNode<int>* takeLevelInput(){
    int rootdata;
    cout<<"Enter root data : ";
    cin>>rootdata;

    if(rootdata==-1) return NULL;

    BinaryNode<int>* root=new BinaryNode<int>(rootdata);

    queue <BinaryNode<int>*> pendingNodes;
    pendingNodes.push(root);
}


int main(){

    // BinaryNode<int>* root=takeinput();
    // printPreOrder(root);

    return 0;
}