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

BinaryTreeNode *insertNode()
{
    int val;
    cout << "Enter the data : ";
    cin >> val;

    if (val == -1)
    {
        return NULL;
    }

    BinaryTreeNode *root = new BinaryTreeNode(val);
    BinaryTreeNode *leftChild = insertNode();
    BinaryTreeNode *rightChild = insertNode();

    root->left = leftChild;
    root->right = rightChild;

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

    inOrder(root->left);
    inOrder(root->right);
    cout << root->data << " ";
}

void levelOrder(BinaryTreeNode *root)
{
    queue<BinaryTreeNode *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        BinaryTreeNode *temp = q.front();

        if (temp == NULL)
        {
            cout << endl;
            q.pop();
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            q.pop();

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
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
    BinaryTreeNode *root = insertNode();
    cout << "PreOrderTraversal : ";
    preOrder(root);
    cout << endl;
    cout << "PostOrderTraversal : ";
    postOrder(root);
    cout << endl;
    cout << "InOrderTraversal : ";
    inOrder(root);
    cout << endl;
    cout << "LevelOrderTraversal : " << endl;
    ;
    levelOrder(root);
    cout << endl;

    return 0;
}
