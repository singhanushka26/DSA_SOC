#include <iostream>
#include <queue>

class Stack {
    std::queue<int> q1, q2;

public:
    Stack() {}

    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        std::swap(q1, q2);
    }

    int pop() {
        if (q1.empty()) {
            return -1;
        }
        int topElement = q1.front();
        q1.pop();
        return topElement;
    }

    int top() {
        if (q1.empty()) {
            return -1;
        }
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    std::cout << s.top() << " is the top element" << std::endl;
    std::cout << s.pop() << " popped from stack" << std::endl;
    std::cout << s.top() << " is the top element" << std::endl;

    std::cout << (s.empty() ? "Stack is empty" : "Stack is not empty") << std::endl;

    return 0;
}
