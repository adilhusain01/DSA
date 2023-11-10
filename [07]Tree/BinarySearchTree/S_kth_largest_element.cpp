#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;

    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

Node *create(Node *root, int data)
{
    if (root == nullptr)
    {
        root = new Node(data);
        return root;
    }

    if (data < root->data)
    {
        root->left = create(root->left, data);
    }

    if (root->data <= data)
    {
        root->right = create(root->right, data);
    }

    return root;
}

Node *insertBST()
{
    int data;
    cout << "Enter the data : ";
    cin >> data;
    Node *root = nullptr;

    if (data == -1)
    {
        return NULL;
    }

    while (data != -1)
    {
        root = create(root, data);
        cout << "Enter the data : ";
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

int solve(Node *root, int &i, int k)
{
    if (root == nullptr)
    {
        return -1;
    }

    int right = solve(root->right, i, k);

    if (right != -1)
    {
        return right;
    }

    i++;

    if (i == k)
    {
        return root->data;
    }

    return solve(root->left, i, k);
}

int kthElement(Node *root, int k)
{
    int i = 0;
    return solve(root, i, k);
}

int main()
{
    // 8 3 10 1 6 14 0 2 4 7 13 -1

    Node *root = insertBST();
    cout << "inOrder : ";
    inOrder(root);

    int k;
    cout << "Enter the kth largest element to find : ";
    cin >> k;

    cout << k << "th Largest element in BST is -> " << kthElement(root, k) << endl;

    return 0;
}