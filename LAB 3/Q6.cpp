#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
ListNode* reverseList(ListNode* head, int B) {
    // TODO: Implement the logic to reverse B nodes of the linked list
    if(head==nullptr)return head;
    ListNode*prev=nullptr,*curr=head,*forward=nullptr;
    for(int i=0;i<B;i++){
        if(forward=nullptr){
            curr->next=prev;
            return curr;
        } 
        forward=curr->next;
        curr=prev;
        prev=curr;
        curr=forward;
    }
    return nullptr; // Placeholder return statement
}

ListNode* reverseAlternateBNodes(ListNode* A, int B) {
        // TODO: Implement logic to reverse every alternate group of B nodes
        if(A==nullptr || A->next==nullptr)return A;
        int count=1;
        ListNode *temp=A,*temphead=A;
        bool check=true;
        while(temp!=nullptr){
            if(count%B==0 || temp->next==nullptr){
                ListNode*next=temp->next;
                if(check){
                ListNode*new_head=reverseList(temphead,B);
                temphead=temp->next;
                count=0;
                if(temphead==A){
                    A=new_head;
                }
                else{
                     temphead=new_head;
                }
                for(int i=0;i<B-1;i++){
                    temphead=temphead->next;
                    temphead->next=next;
                }
                }
                check=!check;
            }
        }
        return A;

}
void append(ListNode*& head, int new_data) {
    ListNode* new_node = new ListNode(new_data);
    if (head == nullptr) {
        head = new_node;
        return;
    }
    ListNode* last = head;
    while (last->next != nullptr) last = last->next;
    last->next = new_node;
}
void printList(ListNode* node) {
    while (node != nullptr) {
        std::cout << node->val << " ";
        node = node->next;
    }
    std::cout << std::endl;
}
int main() {
    ListNode* head = nullptr;
    int n, value, B;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> value;
        append(head, value);
    }
    std::cin >> B;
    head = reverseAlternateBNodes(head, B);
    printList(head);

    return 0;
}