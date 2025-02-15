//Circular Linked List
#include <iostream>

using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Circular Linked List class
class CircularLinkedList {
private:
    Node* tail; 

public:
    CircularLinkedList() {
        tail = nullptr;
    }

    // Insert at the beginning
    void insertAtFront(int value) {
        Node* newNode = new Node(value);

        if (tail == nullptr) { // If list is empty
            tail = newNode;
            tail->next = tail; // Point to itself
        } else {
            newNode->next = tail->next; // Point to head
            tail->next = newNode; // Update tail's next
        }
    }

    // Insert at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);

        if (tail == nullptr) { // If list is empty
            tail = newNode;
            tail->next = tail; // Circular link
        } else {
            newNode->next = tail->next; // Point new node to head
            tail->next = newNode; // Old tail points to new node
            tail = newNode; // Update tail
        }
    }

    // Delete a node by value
    void deleteNode(int value) {
        if (tail == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* current = tail->next;
        Node* previous = tail;

        // If the list contains only one node
        if (tail == tail->next && tail->data == value) {
            delete tail;
            tail = nullptr;
            return;
        }

        // Searching for the node to delete
        do {
            if (current->data == value) {
                previous->next = current->next; // Remove the node
                if (current == tail) { // If deleting the tail node
                    tail = previous;
                }
                delete current;
                return;
            }
            previous = current;
            current = current->next;
        } while (current != tail->next);

        cout << "Node not found!" << endl;
    }

    // Display the list
    void display() {
        if (tail == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = tail->next;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != tail->next);
        cout << "(Head)" << endl;
    }
};

// Main function
int main() {
    CircularLinkedList cll;

    cll.insertAtEnd(10);
    cll.insertAtEnd(20);
    cll.insertAtEnd(30);
    cll.insertAtFront(5);

    cout << "Circular Linked List: ";
    cll.display();

    cll.deleteNode(20);
    cout << "After deleting 20: ";
    cll.display();

    cll.deleteNode(5);
    cout << "After deleting 5: ";
    cll.display();

    return 0;
}
