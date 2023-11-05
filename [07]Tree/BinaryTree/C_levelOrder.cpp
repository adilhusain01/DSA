#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node *insertNode()
{
    int val;
    cout << "Enter the data : ";
    cin >> val;
    if (val == -1)
    {
        return NULL;
    }

    Node *root = new Node(val);
    Node *leftChild = insertNode();
    Node *rightChild = insertNode();

    root->left = leftChild;
    root->right = rightChild;

    return root;
}

void levelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    cout << endl;

    while (!q.empty())
    {
        Node *temp = q.front();

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
    Node *root = insertNode();
    cout << "PreOrderTraversal : ";
    levelOrder(root);

    return 0;
}