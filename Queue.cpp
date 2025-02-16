//Implement a queue using two stacks and analyze its time complexity for enqueue and dequeue operations

#include <iostream>
#include <stack>

class QueueUsingStacks {
private:
    std::stack<int> stack1, stack2;

public:
    // Enqueue operation
    void enqueue(int x) {
        stack1.push(x);
    }

    // Dequeue operation
    int dequeue() {
        if (stack1.empty() && stack2.empty()) {
            std::cout << "Queue is empty\n";
            return -1;
        }

        // If stack2 is empty, move elements from stack1
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        int front = stack2.top();
        stack2.pop();
        return front;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return stack1.empty() && stack2.empty();
    }
};

int main() {
    QueueUsingStacks q;
    
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    std::cout << q.dequeue() << "\n"; // 1
    std::cout << q.dequeue() << "\n"; // 2

    q.enqueue(4);
    std::cout << q.dequeue() << "\n"; // 3
    std::cout << q.dequeue() << "\n"; // 4

    return 0;
}
