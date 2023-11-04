#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;

    Node(int data) : data(data), left(nullptr), right(nullptr) {}
}

struct Node *
levelinput()
{
    int data;
    cout << "Enter the data : ";
    cin >> data;

    if (data == -1)
    {
        return NULL;
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
            temp->left = leftChild;
            q.puush(leftChild);
        }

        int rightData;
        cout << "Enter the right node for " << temp->data << " : ";
        cin >> rightData;
        if (rightData != -1)
        {
            Node *rightChild = new Node(rightData);
            temp->right = rightChild;
            q.push(rightChild);
        }
    }

    return root;
}

void reverseLevelOrder()
{
}

int main()
{
    Node *root = levelinput();
    reverse_levelOrder(root);

    return 0;
}