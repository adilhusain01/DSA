#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;

    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

Node *takeInput()
{
    int data;
    cout << "Enter the data : ";
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    Node *root = new Node(data);
    Node *leftChild = takeInput();
    Node *rightChild = takeInput();

    root->left = leftChild;
    root->right = rightChild;

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

/*
int treeHeight(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int counter = 0;

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            counter++;
            if (!q.empty())
            {
                q.push(NULL);
            }
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

    return counter;
}
*/

int treeHeight(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);

    return max(leftHeight, rightHeight) + 1;
}

int main()
{
    Node *root = takeInput();
    cout << "PreOrder : ";
    preOrder(root);
    cout << "\nHeight of the tree is -> " << treeHeight(root) << endl;

    return 0;
}