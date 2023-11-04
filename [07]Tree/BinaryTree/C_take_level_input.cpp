#include <bits/stdc++.h>
using namespace std;

class BinaryTreeNode
{
public:
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

BinaryTreeNode *insertLevel()
{
    queue<BinaryTreeNode *> q;
    int data;
    cout << "Enter the data for root : ";
    cin >> data;
    BinaryTreeNode *root = new BinaryTreeNode(data);
    q.push(root);

    while (!q.empty())
    {
        BinaryTreeNode *temp = q.front();
        q.pop();

        int leftData;
        cout << "Enter left node for " << temp->data << " : ";
        cin >> leftData;

        if (leftData != -1)
        {
            temp->left = new BinaryTreeNode(leftData);
            q.push(temp->left);
        }

        int rightData;
        cout << "Enter right node for " << temp->data << " : ";
        cin >> rightData;

        if (rightData != -1)
        {
            temp->right = new BinaryTreeNode(rightData);
            q.push(temp->right);
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

int main()
{
    BinaryTreeNode *root = insertLevel();
    cout << "PreOrderTraversal : ";
    preOrder(root);

    return 0;
}