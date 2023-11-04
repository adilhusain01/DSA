#include <iostream>
using namespace std;

struct Node
{
    int key;
    struct *left, *right;

    Node(int key) : key(key), left(nullptr), right(nullptr) {}
}

Node *
insert(int key, Node *node)
{
    if (node == nullptr)
    {
        return Node(key);
    }
}

int main()
{

    return 0;
}