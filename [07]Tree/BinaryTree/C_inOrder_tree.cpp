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

void inOrder(BinaryTreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    inOrder(root->left);
    inOrder(root->right);
    cout << root->data << " ";
}

int main()
{
    BinaryTreeNode *root = insertNode();
    cout << "PreOrderTraversal : ";
    inOrder(root);

    return 0;
}