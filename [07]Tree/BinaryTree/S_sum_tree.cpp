#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;

    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

Node *
levelInput()
{
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

pair<bool, int> checkSum(Node *root)
{
    if (root == nullptr)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    pair<bool, int> left = checkSum(root->left);
    pair<bool, int> right = checkSum(root->right);

    pair<bool, int> ans;

    bool flag;

    if (root->left && root->right)
    {
        flag = (left.second + right.second == root->data);
    }
    else if (root->left && !root->right)
    {
        flag = (left.second == root->data);
    }
    else if (!root->left && root->right)
    {
        flag = (right.second == root->data);
    }
    else
    {
        flag = true;
    }

    ans.second = left.second + right.second + root->data;
    ans.first = left.first && right.first && flag;

    return ans;
}

bool isSum(Node *root)
{
    return checkSum(root).first;
}

int main()
{
    Node *root = levelInput();
    cout << "This is -> ";

    if (isSum(root))
    {
        cout << "a Sum Tree" << endl;
    }
    else
    {
        cout << "not a Sum Tree" << endl;
    }

    return 0;
}