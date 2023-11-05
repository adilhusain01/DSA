#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node *insertNode()
{
    int val;
    cout << "Enter the data : ";
    cin >> val;

    if (val == -1)
    {
        return NULL;
    }

    Node *root = new Node(val);
    Node *leftChild = insertNode();
    Node *rightChild = insertNode();

    root->left = leftChild;
    root->right = rightChild;

    return root;
}

void preOrder(Node *root)
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
    Node *root = insertNode();
    cout << "PreOrderTraversal : ";
    preOrder(root);

    return 0;
}