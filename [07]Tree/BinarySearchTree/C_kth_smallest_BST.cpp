#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;

    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

int solve(Node *root, int &i, int k)
{
    // base case
    if (root == nullptr)
    {
        return -1;
    }

    // search in left subtree
    int left = solve(root->left, i, k);

    // if found it, return it
    if (left != -1)
    {
        return left;
    }

    // search in its right subtree
    i++;

    // if its numbering then shift to upwards at the int left of parent
    if (i == k)
    {
        return root->data;
    }

    return solve(root->right, i, k);
}

int kthElement(Node *root, int k)
{
    int i = 0;
    return solve(root, i, k);
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

int main()
{
    // 8 3 10 1 6 14 0 2 4 7 13 -1
    Node *root = insertInput();

    int k;
    cout << "Enter the kth smallest element to find : ";
    cin >> k;
    cout << k << "\nThe smallest Element is -> " << kthElement(root, k) << endl;

    return 0;
}