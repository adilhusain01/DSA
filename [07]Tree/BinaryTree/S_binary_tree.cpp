#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node *
takeInput()
{
    cout << "##  This is a -1 Input  ##" << endl
         << endl;
    int data;
    cout << "Enter the value : ";
    cin >> data;

    if (data != -1)
    {
        Node *temp = new Node(data);

        Node *leftChild = takeInput();
        temp->left = leftChild;

        Node *rightChild = takeInput();
        temp->right = rightChild;

        return temp;
    }
    else
    {
        return nullptr;
    }
}

Node *levelInput()
{
    cout << "##  This is a level Input  ##"
         << "\n"
         << endl;

    int data;
    cout << "Enter the data : ";
    cin >> data;

    queue<Node *> q;
    Node *root = new Node(data);
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        int leftData;
        cout << "Enter left node of " << temp->data << " : ";
        cin >> leftData;
        if (leftData != -1)
        {
            Node *leftNode = new Node(leftData);
            temp->left = leftNode;
            q.push(leftNode);
        }

        int rightData;
        cout << "Enter right node of " << temp->data << " : ";
        cin >> rightData;
        if (rightData != -1)
        {
            Node *rightNode = new Node(rightData);
            temp->right = rightNode;
            q.push(rightNode);
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

void postOrder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    postOrder(root->left);
    cout << root->data << " ";
    postOrder(root->right);
}

void inOrder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void levelOrder(Node *root)
{
    queue<Node *> q;
    if (root == nullptr)
    {
        return;
    }

    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";

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
}

int main()
{
    Node *root = levelInput();
    levelOrder(root);

    return 0;
}

// takeInput 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
// levelInput 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1