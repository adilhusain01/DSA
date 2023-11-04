#include <bits/stdc++.h>
using namespace std;

struct BinaryTreeNode
{
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

BinaryTreeNode *
takeInput()
{
    cout << "##  This is a -1 Input  ##" << endl
         << endl;
    int data;
    cout << "Enter the value : ";
    cin >> data;

    if (data != -1)
    {
        BinaryTreeNode *temp = new BinaryTreeNode(data);

        BinaryTreeNode *leftChild = takeInput();
        temp->left = leftChild;

        BinaryTreeNode *rightChild = takeInput();
        temp->right = rightChild;

        return temp;
    }
    else
    {
        return nullptr;
    }
}

BinaryTreeNode *levelInput()
{
    cout << "##  This is a level Input  ##"
         << "\n"
         << endl;

    int data;
    cout << "Enter the data : ";
    cin >> data;

    queue<BinaryTreeNode *> q;
    BinaryTreeNode *root = new BinaryTreeNode(data);
    q.push(root);

    while (!q.empty())
    {
        BinaryTreeNode *temp = q.front();
        q.pop();

        int leftData;
        cout << "Enter left node of " << temp->data << " : ";
        cin >> leftData;
        if (leftData != -1)
        {
            BinaryTreeNode *leftNode = new BinaryTreeNode(leftData);
            temp->left = leftNode;
            q.push(leftNode);
        }

        int rightData;
        cout << "Enter right node of " << temp->data << " : ";
        cin >> rightData;
        if (rightData != -1)
        {
            BinaryTreeNode *rightNode = new BinaryTreeNode(rightData);
            temp->right = rightNode;
            q.push(rightNode);
        }
    }

    return root;
}

void preOrder(BinaryTreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(BinaryTreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    postOrder(root->left);
    cout << root->data << " ";
    postOrder(root->right);
}

void inOrder(BinaryTreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void levelOrder(BinaryTreeNode *root)
{
    queue<BinaryTreeNode *> q;
    if (root == nullptr)
    {
        return;
    }

    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        BinaryTreeNode *temp = q.front();
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
    BinaryTreeNode *root = levelInput();
    levelOrder(root);

    return 0;
}

// takeInput 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
// levelInput 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1