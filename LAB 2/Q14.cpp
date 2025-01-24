// Write a program to flip a segment of a singly linked list. A head will be given and two integers that will denote two indices in the list. Now, do the following as shown:

// Input list: 1->2->3->4->5->6->7  And 3,6

// Output list: 1->2->6->5->4->3->7

#include <iostream>
using namespace std;
struct ListNode {
    int value;
    ListNode *next;
    ListNode(int val) : value(val), next(nullptr) {}
};

void printList(ListNode *head) {
    ListNode *temp = head;
    while (temp) {
        cout << temp->value;
        if (temp->next) cout << "->";
        temp = temp->next;
    }
    cout << endl;
}


 ListNode* reverseSegment(ListNode *head, int left, int right) {
    if (!head || left == right) return head;
    
    ListNode temp(0);
    temp.next = head;
    ListNode* prev = &temp;
    
    for (int i = 0; i < left - 1; i++) {
        if (!prev->next) return head; 
        prev = prev->next;
    }
    
    ListNode* start = prev->next;
    ListNode* newprev = start->next;
    
    for (int i = 0; i < right - left; i++) {
        if (!newprev) break; 
        start->next = newprev->next;
        newprev->next = prev->next;
        prev->next = newprev;
        newprev = start->next;
    }
    
    return temp.next;
}


int main() {
    
    int value;
    ListNode *head = nullptr, *tail = nullptr;
    while (cin >> value) {
        if (value == -1) break;
        ListNode *newNode = new ListNode(value);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    int left, right;
    cin >> left >> right;
    cout << "Original list: ";
    printList(head);
    head = reverseSegment(head, left, right);
    cout << "Modified list: ";
    printList(head);
    ListNode *temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
