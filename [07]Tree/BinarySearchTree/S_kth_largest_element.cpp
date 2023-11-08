#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;

    Node(int data) : left(nullptr), right(nullptr) {}
};

Node *levelInput()
{
    int data;
    cout << "Enter the data : ";
    cin >> data;

    if (data == -1)
    {
        return nullptr;
    }

    Node *root = new Node(data);

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        int leftData;
        cout << "Enter the left node for " << temp->data << " : ";
        cin >> leftData;

        if (leftData != -1)
        {
            Node *leftChild = new Node(leftData);
            q.push(leftChild);
            temp->left = leftChild;
        }

        int rightData;
        cout << "Enter the right node for " << temp->data << " : ";
        cin >> rightData;

        if (rightData != -1)
        {
            Node *rightChild = new Node(rightData);
            q.push(rightChild);
            temp->right = rightChild;
        }
    }

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
    Node *root = levelInput();
    cout << "PreOrder : ";
    preOrder(root);

    return 0;
}