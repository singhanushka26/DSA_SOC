#include <iostream>
#include <stack>

class Queue {
    std::stack<int> s1, s2;

public:
    Queue() {}

    void push(int x) {
        s1.push(x);
    }

    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (s2.empty()) {
            return -1; // Queue is empty
        }
        int front = s2.top();
        s2.pop();
        return front;
    }

    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (s2.empty()) {
            return -1; // Queue is empty
        }
        return s2.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);

    std::cout << q.peek() << " is the front element" << std::endl;
    std::cout << q.pop() << " popped from queue" << std::endl;
    std::cout << q.peek() << " is the front element" << std::endl;

    std::cout << (q.empty() ? "Queue is empty" : "Queue is not empty") << std::endl;

    return 0;
}
