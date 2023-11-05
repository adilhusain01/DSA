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
    a if (val == -1)
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

void inOrder(Node *root)
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
    Node *root = insertNode();
    cout << "PreOrderTraversal : ";
    inOrder(root);

    return 0;
}