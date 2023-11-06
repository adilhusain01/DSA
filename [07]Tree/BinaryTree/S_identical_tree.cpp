#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;

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

bool identicalTree(Node *tree1, Node *tree2)
{
    if (tree1 == nullptr && tree2 == nullptr)
    {
        return true;
    }
    else if (tree1 == nullptr && tree2 != nullptr)
    {
        return false;
    }
    else if (tree1 != nullptr && tree2 == nullptr)
    {
        return false;
    }

    bool left = identicalTree(tree1->left, tree2->left);
    bool right = identicalTree(tree1->right, tree2->right);

    bool isSame = (tree1->data == tree2->data);

    return (left && right && isSame);
}

int main()
{
    cout << "** First Tree **\n\n";
    Node *tree1 = levelInput();

    cout << "\n** Second Tree **\n\n";
    Node *tree2 = levelInput();

    cout << "\n\nTree1 and Tree2 are -> ";
    if (identicalTree(tree1, tree2))
    {
        cout << "identical." << endl;
    }
    else
    {
        cout << "not identical." << endl;
    }

    return 0;
}