#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;

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

/*
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

int diaTree(Node *root)
{
    //O(n^2) time complexity

    if (root == nullptr)
    {
        return 0;
    }

    int op1 = diaTree(root->left);
    int op2 = diaTree(root->left);
    int op3 = treeHeight(root->left) + 1 + treeHeight(root->right);

    int ans = max(op1, max(op2, op3));
    return ans;
}
*/

pair<int, int> diaFast(Node *root)
{
    // O(n) time complexity

    if (root == nullptr)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = diaFast(root->left);
    pair<int, int> right = diaFast(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + 1 + right.second;

    pair<int, int> ans;
    ans.first = max(op1, max(op2, op3));
    ans.second = max(left.second, right.second) + 1;

    return ans;
}

int diaTree(Node *root)
{
    return diaFast(root).first;
}

int main()
{
    Node *root = levelInput();
    cout << "Diameter of the tree is -> " << diaTree(root) << endl;

    return 0;
}