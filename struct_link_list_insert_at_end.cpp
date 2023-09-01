#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "nullptr" << std::endl;
}

int main() {

    int size;
    cout << "Enter the amount of data inputs : ";
    cin >> size;

    Node* mylist = nullptr;

    for (int i = 0; i < size; i++) {
        int temp;
        cout << "Enter data item " << i + 1 << " to insert at end : ";
        cin >> temp;
        insertAtEnd(mylist, temp);
    }

    printList(mylist);

    return 0;
}
