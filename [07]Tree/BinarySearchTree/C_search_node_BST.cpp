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
    else
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

bool searchNode(Node *root, int data)
{

    if (root == nullptr)
    {
        return false;
    }
    else if (root->data == data)
    {
        return true;
    }

    if (data < root->data)
    {
        return searchNode(root->left, data);
    }

    else
    {
        return searchNode(root->right, data);
    }
}

int main()
{
    // 8 3 1 6 10 14 13 4 7 -1
    // 2 or 14

    Node *root = insertInput();

    int findMe;
    cout << "\n\nEnter the Node to find : ";
    cin >> findMe;

    if (searchNode(root, findMe))
    {
        cout << "Node present" << endl;
    }
    else
    {
        cout << "Node not present" << endl;
    }

    return 0;
}