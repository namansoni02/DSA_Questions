// Problem:
// Given a linked list and a list of operations to be performed on the list, print the linked list after each operation.
// There are two types of operations, insertion and deletion. Insertion involves inserting the given element at the front of the linked list, and deletion involves removing the element from the front of the linked list. This will demonstrate the Last In First Out (LIFO) operations in a linked list.

// Input Format:
// First line contains an integer n, the initial number of elements in the linked list.
// Second line contains n integers, denoting the initial elements of the linked list.
// Third line contains an integer m, the number of operations to be performed.
// Next m lines contain two integers each, a & b:
// If a == 1, insert b at the front of the linked list.
// If a == 2, b will always be -1; perform deletion from the front of the linked list.

// Output Format:
// Print m lines, showing the linked list after each operation.

// Sample Test Case:
// Input:
// 5
// 1 2 3 4 5
// 4
// 1 10
// 2 -1
// 2 -1
// 1 20

// Output:
// 10 5 4 3 2 1 NULL
// 5 4 3 2 1 NULL
// 4 3 2 1 NULL
// 20 4 3 2 1 NULL

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
    LinkedList(node* h=NULL){
        head = h;
    }
    void insert(int val){
        // complete this insert function
        node* newNode = new node(val);
        if (head == nullptr) {
            head =  newNode;
        } else {
            node*ptr=head;
            newNode->next=head;
            head=newNode;
        }
    }

    void printLinkedList(){
        // don't alter this printing function
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


void insertion_operation(LinkedList &l,int elem){
    // insert the new elem at the back
    node* newnode=new node();
    newnode->val=elem;
    newnode->next=l.head;
    l.head=newnode;
    return;
}

node* deletion_operation(LinkedList &l){
    // delete the elem from the front
    if(l.head==NULL)return NULL;
    else{
        node* temp=l.head;
        l.head=l.head->next;
        delete temp;
        return l.head;
    }

}

int main(){
    // initialize the linked list 
    int n; cin>>n;
    LinkedList list;
    
    // take input for linked list
    for(int i=0;i<n;i++){
        int x; cin>>x;
        list.insert(x);
    }
    // take input for the operations
    int m; cin>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        if(a==1){
            insertion_operation(list,b);
        }
        else{
            list.head=deletion_operation(list);
        }
        list.printLinkedList();
    }
    // perform operation and after the operation print the list
    
    
    return 0;
}