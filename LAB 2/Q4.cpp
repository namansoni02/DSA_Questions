// Given an array of elements, insert all the elements in a Linked List in sorted order. The insertion function should be called everytime you add an element to the linked list and it should be implemented in such a way that the inserted element goes to its correct position in the sorted order.
// NOTE : You must NOT sort the array and then create a Linked List.

// Input Format : First line of the input contains an integer 'n', representing the size of the input array. Next line contains n integers representing the elements in the array.

// Output Format : Print the elements in the sorted linked list.

// Example Input : 
// 5
// 3 11 9 16 15
// Example Output : 
// 3 9 11 15 16

#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int val;
    node*next;
    node(int val){
        this->val=val;
        this->next=NULL;
    }
};

class LinkedList {
public:
    node* head;
    LinkedList(node* h = NULL) {
        head = h;
    }
    
    void insert_sorted(int val) {
        // Add insertion logic here.
        node *newnode=new node(val);
        if(head==NULL){
            head=newnode;
            return;
        }
        else{
            if(head->val>val){
                newnode->next=head;
                head=newnode;
                return;
            }
            else{
                node*temp=head;
                node* prev=head;
                while(temp!=NULL && temp->val<val){
                    prev=temp;
                    temp=temp->next;
                }
                prev->next=newnode;
                newnode->next=temp;
            }
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

int main() {
    LinkedList list;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        list.insert_sorted(x);
    }
    // Add your code here.
    list.printLinkedList();

    return 0;
}