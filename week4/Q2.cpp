#include <iostream>
#define MAX 1000

class Queue {
    int front, rear, size;
    int arr[MAX];

public:
    Queue() {
        front = 0;
        rear = 0;
        size = 0;
    }

    void push(int x) {
        if (size >= MAX) {
            std::cout << "Queue Overflow" << std::endl;
            return;
        }
        arr[rear] = x;
        rear = (rear + 1) % MAX;
        size++;
    }

    int pop() {
        if (size <= 0) {
            return -1;
        }
        int item = arr[front];
        front = (front + 1) % MAX;
        size--;
        return item;
    }

    bool isEmpty() {
        return (size == 0);
    }
};

int main() {
    Queue q;
    int queries;
    std::cin >> queries;

    while (queries--) {
        int type;
        std::cin >> type;

        if (type == 1) {
            int x;
            std::cin >> x;
            q.push(x);
        } else if (type == 2) {
            int result = q.pop();
            if (result == -1) {
                std::cout << "Queue is empty" << std::endl;
            } else {
                std::cout << result << std::endl;
            }
        }
    }

    return 0;
}
