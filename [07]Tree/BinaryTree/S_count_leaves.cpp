#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;

    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

struct Node *
levelInput()
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
        cout << "Enter the left node of " << temp->data << " : ";
        cin >> leftData;
        if (leftData != -1)
        {
            Node *leftChild = new Node(leftData);
            temp->left = leftChild;
            q.push(leftChild);
        }

        int rightData;
        cout << "Enter the right node of " << temp->data << " : ";
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

void countLeaves(Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    int counter = 0;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (!(temp->left) && !(temp->right))
        {
            counter++;
        }
        else
        {
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }

    cout << "The tree has " << counter << " leaves" << endl;
}

int main()
{
    Node *root = levelInput();
    countLeaves(root);

    return 0;
}