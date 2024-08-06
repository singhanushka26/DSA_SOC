#include <iostream>

struct ListNode {
    int value;
    ListNode* next;
    ListNode(int x) : value(x), next(nullptr) {}
};

void deleteNode(ListNode* node) {
    if (node == nullptr || node->next == nullptr) {
        return;
    }
    ListNode* temp = node->next;
    node->value = temp->value;
    node->next = temp->next;
    delete temp;
}

void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        std::cout << temp->value << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

int main() {
    ListNode* head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);

    std::cout << "Original List: ";
    printList(head);

    ListNode* nodeToDelete = head->next; // Let's delete the node with value 5
    deleteNode(nodeToDelete);

    std::cout << "List after deleting node: ";
    printList(head);

    return 0;
}
