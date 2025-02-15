//Double Linked List

#include <iostream>

using namespace std;

// Node structure for the doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

// Doubly Linked List class
class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    // Insert at the front
    void insertAtFront(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Insert at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }

    // Delete a node by value
    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;

        // If the node to be deleted is the head node
        if (temp->data == value) {
            head = temp->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            delete temp;
            return;
        }

        // Search for the node to be deleted
        while (temp != nullptr && temp->data != value) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Node not found!" << endl;
            return;
        }

        // Adjust pointers to remove the node
        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }

        if (temp->prev != nullptr) {
            temp->prev->next = temp->next;
        }

        delete temp;
    }

    // Display the list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

// Main function
int main() {
    DoublyLinkedList dll;

    dll.insertAtFront(10);
    dll.insertAtFront(20);
    dll.insertAtEnd(30);
    dll.insertAtEnd(40);

    cout << "Doubly Linked List: ";
    dll.display();

    dll.deleteNode(20);
    cout << "After deleting 20: ";
    dll.display();

    dll.deleteNode(40);
    cout << "After deleting 40: ";
    dll.display();

    return 0;
}
