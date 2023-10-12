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

    ~BinaryNode(){
        delete left;
        delete right;
    } 
};


//Preorder
//printing root then left then right subtree
 
void printPreOrder(BinaryNode<int>* root){
    if(root==NULL) return;

    cout<<root->data<<" ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

void printInOrder(BinaryNode<int>* root){
    if(root==NULL) return;

    printInOrder(root->left);
    cout<<root->data<<" ";
    printInOrder(root->right);
}

void printPostOrder(BinaryNode<int>* root){
    if(root==NULL) return;

    printPostOrder(root->left);
    printPostOrder(root->right);
    cout<<root->data;
}

int main(){
    BinaryNode<int>* root=new BinaryNode<int>(1);
    BinaryNode<int>* node1= new BinaryNode<int>(2);
    BinaryNode<int>* node2= new BinaryNode<int>(3);

    BinaryNode<int>* node3= new BinaryNode<int>(4);
    BinaryNode<int>* node4= new BinaryNode<int>(5);

    BinaryNode<int>* node5= new BinaryNode<int>(6);
    BinaryNode<int>* node6= new BinaryNode<int>(7);

    //root=1
    root->left=node1; // root->left=2
    root->right=node2; // roots->right=3

    node1->left=node3; // root->left->left=4
    node1->right=node4; // root->left->right=5

    node2->left=node5; // root->rigjt->left=6
    node2->right=node6; // root->right->right=7

    // printPreOrder(root);
    printInOrder(root);

    return 0;
}