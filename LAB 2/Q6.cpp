// A Linked List is a linear data structure where elements, called nodes, are stored in a sequence. Each node contains a value and a reference (or pointer) to the next node in the sequence, allowing for dynamic memory allocation and efficient insertion or deletion of elements. The starting node of a linked list is called its head. 

// Problem:
// Given a linked list and a list of operations to be performed on the list, print the linked list after each operation. 
// There are two types of operations, insertion and deletion. Insertion involves inserting the given element at the end of the linked list and deletion involves removing the element from the front of the linked list. Which will demonstrate the First In First Out (FIFO) operations in a linked list.

// Input Format:
// First line contains an integers n, the initial number of elements in the linked list.
// Second line contains n integers, denoting the initial elements of linked list.
// Third line contains an integer m.
// Next m lines contain two integers each, a & b. 
//                                       --- if a==1, insert b. 
//                                       --- if a==2, b will be always -1, perform deletion.

// Output Format:
// Print m lines, the linked list after each operation.


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
// 1 2 3 4 5 10 NULL
// 2 3 4 5 10 NULL
// 3 4 5 10 NULL
// 3 4 5 10 20 NULL


#include <bits/stdc++.h>
using namespace std;

#define repeat(i,s,e) for(long long i=s;i<e;i++)

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
            while(ptr->next!=nullptr){
                ptr=ptr->next;
            }
            ptr->next=newNode;
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

void insertion_operation(LinkedList &l,node* elem){
    // insert the new elem at the back
    if(l.head==nullptr){
        l.head=elem;
    }
    else{
        node *temp=l.head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=elem;
    }
}

node* deletion_operation(LinkedList &l){
    // delete the elem from the front
    if(l.head==nullptr)return nullptr;
    node *temp=l.head;
    l.head=l.head->next;
    delete temp;
    return l.head;
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
            node*temp=new node(b);
            insertion_operation(list,temp);
        }
        else{
            list.head=deletion_operation(list);
        }
        list.printLinkedList();
    }
    // perform operation and after the operation print the list
    
    return 0;
}