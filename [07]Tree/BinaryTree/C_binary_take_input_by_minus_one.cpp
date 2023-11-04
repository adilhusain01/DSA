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

    cout << endl;

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

void insertLevel(BinaryTreeNode *&root)
{
    queue<BinaryTreeNode *> q;
    int data;
    cout << "Enter the data for root : ";
    cin >> data;
    root = new BinaryTreeNode(data);
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
}

int main()
{
    // // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
    // BinaryTreeNode *root = insertNode();
    // cout << "PreOrderTraversal : ";
    // preOrder(root);
    // cout << endl;
    // cout << "PostOrderTraversal : ";
    // postOrder(root);
    // cout << endl;
    // cout << "InOrderTraversal : ";
    // inOrder(root);
    // cout << endl;
    // cout << "LevelOrderTraversal : " << endl;
    // ;
    // levelOrder(root);
    // cout << endl;

    // 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    BinaryTreeNode *root = NULL;
    insertLevel(root);

    levelOrder(root);

    return 0;
}
