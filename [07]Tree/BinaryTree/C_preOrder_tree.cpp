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

    if (val == -1)
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

void preOrder(BinaryTreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main()
{
    BinaryTreeNode *root = insertNode();
    cout << "PreOrderTraversal : ";
    preOrder(root);

    return 0;
}