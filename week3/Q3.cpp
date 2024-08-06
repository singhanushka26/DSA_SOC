#include <iostream>

struct ListNode {
    int value;
    ListNode* next;
    ListNode(int x) : value(x), next(nullptr) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode* first = &dummy;
    ListNode* second = &dummy;

    for (int i = 0; i <= n; ++i) {
        first = first->next;
    }

    while (first != nullptr) {
        first = first->next;
        second = second->next;
    }

    ListNode* nodeToDelete = second->next;
    second->next = second->next->next;
    delete nodeToDelete;

    return dummy.next;
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
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    std::cout << "Original List: ";
    printList(head);

    int n = 2;
    head = removeNthFromEnd(head, n);

    std::cout << "List after removing " << n << "th node from end: ";
    printList(head);

    return 0;
}
