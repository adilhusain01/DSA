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
};

int main()
{
    Node<int> *root = new Node<int>(1);
    Node<int> *leftchild = new Node<int>(2);
    Node<int> *rightchild = new Node<int>(3);

    root->left = leftchild;
    root->right = rightchild;

    cout << "Root data -> " << root->data << endl;
    cout << "Left child data -> " << root->left->data << endl;
    cout << "Right child data -> " << root->right->data << endl;

    return 0;
}