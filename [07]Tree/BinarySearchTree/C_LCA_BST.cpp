#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

Node *makeBST(Node *root, int data)
{
    if (root == nullptr)
    {
        root = new Node(data);
        return root;
    }

    if (data < root->data)
    {
        root->left = makeBST(root->left, data);
    }
    else
    {
        root->right = makeBST(root->right, data);
    }

    return root;
}

Node *takeInput()
{
    int data;
    cout << "Enter the data : ";
    cin >> data;

    Node *root = nullptr;

    while (data != -1)
    {
        root = makeBST(root, data);
        cin >> data;
    }

    return root;
}

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

int LCA(Node *root, int data1, int data2)
{
    if (data1 < root->data && data2 < root->data)
    {
        while (data1 < root->data && data2 < root->data)
        {
            root = root->left;
        }
    }
    else if (data1 >= root->data && data2 >= root->data)
    {
        while (data1 >= root->data && data2 >= root->data)
        {
            root = root->left;
        }
    }

    Node *leftSubtree = root->left;
    Node *rightSubtree = root->right;

    while (data1 != leftSubtree->data)
    {
        if (data1 < leftSubtree->data)
        {
            leftSubtree = leftSubtree->left;
        }
        else
        {
            leftSubtree = leftSubtree->right;
        }
    }

    while (data2 != rightSubtree->data)
    {
        if (data2 < rightSubtree->data)
        {
            rightSubtree = rightSubtree->left;
        }
        else
        {
            rightSubtree = rightSubtree->right;
        }
    }

    return root->data;
}

int main()
{
    Node *root = takeInput();
    int x = 25, y = 60;
    cout << LCA(root, x, y) << endl;

    return 0;
}