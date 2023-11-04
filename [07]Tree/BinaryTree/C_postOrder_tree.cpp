#include <bits/stdc++.h>
using namespace std;

class BinaryTreeNode
{
public:
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

BinaryTreeNode *insertNode()
{
    int val;
    cout << "Enter the data : ";
    cin >> val;
    a if (val == -1)
    {
        return NULL;
    }

    BinaryTreeNode *root = new BinaryTreeNode(val);
    BinaryTreeNode *leftChild = insertNode();
    BinaryTreeNode *rightChild = insertNode();

    root->left = leftChild;
    root->right = rightChild;

    return root;
}

void postOrder(BinaryTreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    postOrder(root->left);
    cout << root->data << " ";
    postOrder(root->right);
}

int main()
{
    BinaryTreeNode *root = insertNode();
    cout << "PreOrderTraversal : ";
    postOrder(root);

    return 0;
}