#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;

    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

Node *levelInput()
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
        cout << "Enter left node for " << temp->data << " : ";
        cin >> leftData;
        if (leftData != -1)
        {
            Node *leftChild = new Node(leftData);
            q.push(leftChild);
            temp->left = leftChild;
        }

        int rightData;
        cout << "Enter right node for " << temp->data << " : ";
        cin >> rightData;
        if (rightData != -1)
        {
            Node *rightChild = new Node(rightData);
            q.push(rightChild);
            temp->right = rightChild;
        }
    }

    return root;
}

/*
int treeHeight(Node *root)
{
    //O(n^2) time complexity

    if (root == nullptr)
    {
        return 0;
    }

    int leftSubtree = treeHeight(root->left);
    int rightSubtree = treeHeight(root->right);

    return max(leftSubtree, rightSubtree) + 1;
}

bool checkBalanced(Node *root)
{
    if (root == nullptr)
    {
        return true;
    }

    bool leftCheck = checkBalanced(root->left);
    bool rightCheck = checkBalanced(root->right);
    bool heightcheck = ((abs(treeHeight(root->left) - treeHeight(root->right))) <= 1);

    return (leftCheck && rightCheck && heightcheck);
}
*/

pair<bool, int> chk(Node *root)
{
    if (root == nullptr)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    pair<bool, int> left = chk(root->left);
    pair<bool, int> right = chk(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;

    bool diff = abs(left.second - right.second) <= 1;

    pair<bool, int> ans;
    ans.second = max(left.second, right.second) + 1;
    if (leftAns && rightAns && diff)
    {
        ans.first = true;
    }
    else
    {
        ans.first = false;
    }

    return ans;
}

bool chkBalanced(Node *root)
{
    // O(h) time complexity

    return chk(root).first;
}

int main()
{
    Node *root = levelInput();
    cout << "The tree is ";
    if (chkBalanced(root) == true)
    {
        cout << "balanced." << endl;
    }
    else
    {
        cout << "unbalanced." << endl;
    }

    return 0;
}