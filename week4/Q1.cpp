#include <iostream>
#define MAX 1000

class Stack {
    int top;
    int arr[MAX];

public:
    Stack() {
        top = -1;
    }

    void push(int x) {
        if (top >= MAX - 1) {
            std::cout << "Stack Overflow" << std::endl;
            return;
        }
        arr[++top] = x;
    }

    int pop() {
        if (top < 0) {
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (top < 0) {
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() {
        return (top < 0);
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    std::cout << s.pop() << " popped from stack" << std::endl;
    std::cout << "Top element is " << s.peek() << std::endl;

    return 0;
}
