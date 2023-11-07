#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;

    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

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

int maxNode(Node *root)
{
    if (root->right == nullptr)
    {
        return root->data;
    }

    int right = maxNode(root->right);

    return right;
}

int minNode(Node *root)
{
    if (root->left == nullptr)
    {
        return root->data;
    }

    int left = minNode(root->left);

    return left;
}

int main()
{
    Node *root = insertInput();

    cout << "\nMaxNode -> " << maxNode(root) << endl;
    cout << "MinNode -> " << minNode(root) << endl;

    return 0;
}