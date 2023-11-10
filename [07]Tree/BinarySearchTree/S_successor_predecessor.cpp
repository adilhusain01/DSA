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

pair<int, int> find_pred_suc(Node *root, int key)
{
    Node *temp = root;
    int pred = -1;
    int suc = -1;

    // finding key

    while (temp->data != key)
    {
        if (key < temp->data)
        {
            suc = temp->data;
            temp = temp->left;
        }
        else
        {
            pred = temp->data;
            temp = temp->right;
        }
    }

    // predecessor

    Node *rightSubtree = temp->right;
    Node *leftSubtree = temp->left;

    while (leftSubtree != nullptr)
    {
        pred = leftSubtree->data;
        leftSubtree = leftSubtree->right;
    }

    while (rightSubtree != nullptr)
    {
        suc = rightSubtree->data;
        rightSubtree = rightSubtree->left;
    }

    return {pred, suc};
}

int main()
{
    Node *root = insertInput();

    int key;
    cout << "Enter the key to find its pre and succ : ";
    cin >> key;

    pair<int, int> p = find_pred_suc(root, key);

    cout << "Predecessor -> " << p.first << " Successor -> " << p.second << endl;

    return 0;
}