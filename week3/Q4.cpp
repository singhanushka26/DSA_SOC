#include <iostream>

struct ListNode {
    int value;
    ListNode* next;
    ListNode(int x) : value(x), next(nullptr) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* current = &dummy;
    int carry = 0;
    
    while (l1 != nullptr || l2 != nullptr || carry != 0) {
        int sum = carry;
        if (l1 != nullptr) {
            sum += l1->value;
            l1 = l1->next;
        }
        if (l2 != nullptr) {
            sum += l2->value;
            l2 = l2->next;
        }
        
        carry = sum / 10;
        current->next = new ListNode(sum % 10);
        current = current->next;
    }
    
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
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    std::cout << "List 1: ";
    printList(l1);

    std::cout << "List 2: ";
    printList(l2);

    ListNode* result = addTwoNumbers(l1, l2);

    std::cout << "Sum: ";
    printList(result);

    return 0;
}
