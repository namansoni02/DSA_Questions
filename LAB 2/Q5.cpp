// A Linked List is a linear data structure where elements, called nodes, are stored in a sequence. Each node contains a value and a reference (or pointer) to the next node in the sequence, allowing for dynamic memory allocation and efficient insertion or deletion of elements. The starting node of a linked list is called its head. 

// Problem:
// Given heads of two linked lists, concatenate the linked lists such that the concatenated list is sorted. (You can assume that the original lists are sorted already)

// Input Format:
// First line contains two integers n and m, the lengths of the two linked lists. 0 <= n,m <= 100
// Second line contains n integers, values for linked list 1. This line will not be present if n=0
// Third line contains m integers, values for linked list 2. This line will not be present if m=0

// Output Format:
// Print the resulting big linked list.


// Sample Test Case:
// Input:
// 2 3
// 1 2
// 1 2 5

// Output:
// 1 1 2 2 5 NULL

#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int val;
    node* next;
    node(int v=0,node* nxt=NULL){
        val = v;
        next = nxt;
    }
};

class LinkedList{
    public:
    node* head;
    node* tail;

    LinkedList(node* h=NULL){
        head = h;
        tail=h;
    }
    void insert(int val){
        // complete this insert function
        node* newNode = new node(val);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void printLinkedList(){
        if (head==NULL){
            cout<<"EMPTY\n";
            return;
        }
        node* curr = head;
        while(curr){
            cout<<curr->val<<' ';
            curr = curr->next;
        }
        cout<<"NULL\n";
    }
};

node* concatenate(node* head1,node* head2){
    // well not needed but you can get it from previous question
    node *ptr1=head1;
    node *ptr2=head2;
    while(ptr2!=NULL){
        node*newnode=new node(ptr2->val);
        if(ptr1->val > ptr2->val){
            newnode->next=ptr1;
            ptr1=newnode;
            ptr2=ptr2->next;
        }
        else if(ptr1->val < ptr2->val && ptr1->next->val < ptr2->val){
            ptr1=ptr1->next;
        }
        else{
            node * temp=ptr1->next;
            ptr1->next=newnode;
            newnode->next=temp;
            ptr2=ptr2->next;
        }   
    }
    return head1;
    
}

node* sortedConcatenate(node* head1, node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    node* ptr1 = head1;
    node* ptr2 = head2;

    while (ptr2 != NULL) {
        if (ptr1->val >= ptr2->val) {
        node* newHead = ptr2;
        ptr2 = ptr2->next;
        newHead->next = head1;
        head1 = newHead;
        ptr1 = head1;  
        }
        if (ptr1->next == NULL || ptr1->next->val >= ptr2->val) {
            node* newnode = new node(ptr2->val);
            newnode->next = ptr1->next;
            ptr1->next = newnode;
            ptr2 = ptr2->next;
        } else {
            ptr1 = ptr1->next;
        }
    }

    return head1;
}


int main(){
    // Initialize two linked lists
    int n,m;
    cin>>n>>m;
    LinkedList list1,list2;
    // take input and make the linked lists
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        list1.insert(x);
    }
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        list2.insert(x);
    }
    // call the sortedConcatenate function
    list1.head=sortedConcatenate(list1.head,list2.head);
   
    // print the new sorted big linked list using printLinkedList
    list1.printLinkedList();
    
    return 0;
}