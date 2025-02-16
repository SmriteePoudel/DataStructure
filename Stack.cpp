#include <iostream>

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

class Stack {
private:
    Node* top_node;  // Pointer to the top node
    int size;        // Keep track of number of elements

public:
    // Constructor
    Stack() : top_node(nullptr), size(0) {}
    
    // Destructor to free memory
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
    
    // Push operation - O(1)
    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = top_node;
        top_node = newNode;
        size++;
    }
    
    // Pop operation - O(1)
    void pop() {
        if (isEmpty()) {
            std::cout << "Stack Underflow" << std::endl;
            return;
        }
        Node* temp = top_node;
        top_node = top_node->next;
        delete temp;
        size--;
    }
    
    // Top operation - O(1)
    int top() {
        if (isEmpty()) {
            std::cout << "Stack is Empty" << std::endl;
            return -1;
        }
        return top_node->data;
    }
    
    // Check if stack is empty - O(1)
    bool isEmpty() {
        return top_node == nullptr;
    }
    
    // Get size of stack - O(1)
    int getSize() {
        return size;
    }
};

// Example usage
int main() {
    Stack s;
    
    // Push some elements
    s.push(1);
    s.push(2);
    s.push(3);
    
    // Print top element
    std::cout << "Top element: " << s.top() << std::endl;  // Output: 3
    
    // Pop an element
    s.pop();
    std::cout << "After popping, top element: " << s.top() << std::endl;  // Output: 2
    
    // Check size
    std::cout << "Stack size: " << s.getSize() << std::endl;  // Output: 2
    
    return 0;
}