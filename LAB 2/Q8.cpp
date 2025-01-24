// Given an unsorted linked list, your task is to return the second-highest element in the list. If the list contains less than two distinct elements, return NULL.

// Input Format:
// First line of input contains an integer n, representing the number of elements in the linked list initially.
// A second line contains n space-separated integers representing the elements of the linked list.

// Output Format:
// The code should print the second highest element in the linked list and if there are less than 2 elements in the linked list, it should output "NULL".

// Sample Test Case:
// Input:
// 5
// 4 7 2 6 9

// Output:
// 7

#include <bits/stdc++.h>
using namespace std;

class node {
public:
    // Define node attributes.
    int val;
    node* next;
    node(int val){
        this->val=val;
        this->next=nullptr;
    }
};

class LinkedList {
public:
    node* head;
    LinkedList(node* h = NULL) {
        head = h;
    }

    void insert(int val){
        // Add the insertion logic here.
        node*newnode=new node(val);
        if(head==nullptr){
            head=newnode;
        }
        else{
            node* temp=head;
            while(temp->next!=nullptr){
                temp=temp->next;
            }
            temp->next=newnode;
        }
    }

    void printLinkedList() {
        if (head == NULL) {
            cout << "EMPTY\n";
            return;
        }
        node* curr = head;
        while (curr) {
            cout << curr->val << ' ';
            curr = curr->next;
        }
        cout << "NULL\n";
    }

    node* second_highest() {
    if (head == nullptr || head->next == nullptr) {
        return nullptr; 
    }

    node* max = head;
    node* second_max = nullptr;
    node* temp = head->next;

    while (temp != nullptr) {
        if (temp->val > max->val) {
            second_max = max; 
            max = temp; 
        } else if (temp->val < max->val) {
            if (second_max == nullptr || temp->val > second_max->val) {
                second_max = temp; 
            }
        }
        temp = temp->next;
    }

    return second_max;
}

};

int main() {
    // Initialize the linked list.
    LinkedList list;
    // Take the input to linked list.
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        list.insert(x);
    }

    node* result = list.second_highest();

    if (result) {
        cout << result->val << endl;
    } else {
        cout << "NULL" << endl;
    }
    
    return 0;
}