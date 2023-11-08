#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;

    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

void inOrder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

Node *insertToBST(Node *root, int data)
{
    if (root == nullptr)
    {
        root = new Node(data);
        return root;
    }

    if (data < root->data)
    {
        root->left = insertToBST(root->left, data);
    }

    if (root->data <= data)
    {
        root->right = insertToBST(root->right, data);
    }

    return root;
}

Node *insertInput()
{
    cout << "Enter the data : ";
    int data;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    Node *root = nullptr;

    while (data != -1)
    {
        root = insertToBST(root, data);
        cout << "Enter the data : ";
        cin >> data;
    }

    return root;
}

bool isBST(Node *root, int min, int max)
{
    if (root == nullptr)
    {
        return true;
    }

    if ((root->data > min) && (root->data < max))
    {
        bool left = isBST(root->left, min, root->data);
        bool right = isBST(root->right, root->data, max);

        return left && right;
    }
    else
    {
        return false;
    }
}

bool validBST(Node *root)
{
    return isBST(root, INT_MIN, INT_MAX);
}

int main()
{
    Node *root = insertInput();
    cout << "\n\n inOrder -> ";
    inOrder(root);

    if (validBST(root))
    {
        cout << "\nIt's a BST" << endl;
    }
    else
    {
        cout << "\nIt's not BST" << endl;
    }

    return 0;
}