#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

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

void inOrder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int maxNode(Node *root)
{
    if (root->right == nullptr)
    {
        return root->data;
    }

    int right = maxNode(root->right);

    return right;
}

int minNode(Node *root)
{
    if (root->left == nullptr)
    {
        return root->data;
    }

    int left = minNode(root->left);

    return left;
}

Node *insertToBST(Node *root, int data)
{
    if (root == nullptr)
    {
        root = new Node(data);
        return root;
    }

    if (data < root->data)
    {
        root->left = insertToBST(root->left, data);
    }

    if (root->data <= data)
    {
        root->right = insertToBST(root->right, data);
    }

    return root;
}

Node *insertInput()
{
    cout << "Enter the data : ";
    int data;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    Node *root = nullptr;

    while (data != -1)
    {
        root = insertToBST(root, data);
        cout << "Enter the data : ";
        cin >> data;
    }

    return root;
}

Node *deleteNode(Node *root, int data)
{
    if (root == nullptr)
    {
        return root;
    }

    if (root->data == data)
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            return NULL;
        }

        if ((root->left == nullptr && root->right))
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        if ((root->left && root->right == nullptr))
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        if ((root->left && root->right))
        {
            int min = minNode(root->right);
            root->data = min;
            root->right = deleteNode(root->right, min);
            return root;
        }
    }
    else if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
        return root;
    }
    else
    {
        root->right = deleteNode(root->right, data);
        return root;
    }
}

int main()
{
    // Condition : Sorted tree and the node is already present in it which needs to be deleted

    Node *root = insertInput();

    cout << "LevelOrder -> ";
    levelOrder(root);
    cout << "PreOrder -> ";
    preOrder(root);
    cout << "\n\nInOrder -> ";
    inOrder(root);

    int deleteMe;
    cout << "\n\nEnter the Node to delete : ";
    cin >> deleteMe;

    deleteNode(root, deleteMe);

    cout << "LevelOrder -> ";
    levelOrder(root);
    cout << "PreOrder -> ";
    preOrder(root);
    cout << "\n\nInOrder -> ";
    inOrder(root);

    return 0;
}