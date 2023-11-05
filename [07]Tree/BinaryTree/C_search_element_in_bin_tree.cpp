#include <iostream>
using namespace std;

template <typename T>

class Node
{
public:
    T data;
    Node *left;
    Node *right;

    Node(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~Node()
    {
        delete left;
        delete right;
    }
};

bool searchElement(int val, Node<int> *root)
{
    if (root == NULL)
        return false;
    if ((root->data) == val)
        return true;
    return searchElement(val, root->left) || searchElement(val, root->right);
}

int main()
{
    Node<int> *root = new Node<int>(1);
    Node<int> *node1 = new Node<int>(2);
    Node<int> *node2 = new Node<int>(3);

    Node<int> *node3 = new Node<int>(4);
    Node<int> *node4 = new Node<int>(5);

    Node<int> *node5 = new Node<int>(6);
    Node<int> *node6 = new Node<int>(7);

    // root=1
    root->left = node1;  // root->left=2
    root->right = node2; // roots->right=3

    node1->left = node3;  // root->left->left=4
    node1->right = node4; // root->left->right=5

    node2->left = node5;  // root->rigjt->left=6
    node2->right = node6; // root->right->right=7

    if (searchElement(3, root))
    {
        cout << "Node found" << endl;
    }
    else
    {
        cout << "Node not found" << endl;
    }

    return 0;
}