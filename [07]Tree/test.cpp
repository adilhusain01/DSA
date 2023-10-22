#include <iostream>
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

int main()
{
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

    return 0;
}
