// You are provided with a doubly linked list and an integer key. Your task is to remove all occurrences of the key from the list only if it appears at least twice. If the key appears less than twice, the list should remain unchanged.

// Input Format:
// First line of the input contains an integer n representing the number of elements in the doubly linked list.
// Next line contains series of integers to be inserted into the doubly linked list.
// The last line contains single integer representing the key whose occurrences need to be deleted if it appears at least twice.

// Output Format:
// Print the modified linked list after performing the deletion operation, if applicable.

// Example Input:
// 6
// 1 2 2 3 5 4
// 2

// Example Output:
// 1 3 5 4

#include <iostream>
#include<vector>
using namespace std;

// Definition for a doubly linked list node.
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// Function to insert a node at the end of the doubly linked list.
void insert(Node*& head, int data) {
    // Complete this function.
    Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newNode;
        newNode->prev = curr;
}

// Function to delete all occurrences of a key if it appears at least twice in the doubly linked list.
void deleteIfOccursTwice(Node*& head, int key) {
    // Complete this function.
    if(head==nullptr || head->next==nullptr)return;
    vector<Node*>ans;
    Node* temp=head;
    int size=0;
    while(temp!=nullptr){
        if(temp->data==key){
            ans.push_back(temp);
        }
        size++;
        temp=temp->next;
    }
    if(ans.size()==size){
        head=nullptr;
        return;
    }
    if(ans.size()>=2){
        Node * forward=nullptr,*back=nullptr;
        for(auto i:ans){
            //cout<<i->data<<endl;
            forward=i->next;
            back=i->prev;
            if(forward!=nullptr){
                forward->prev=back;
            }
            if(back!=nullptr){
                back->next=forward;
            }
            if(back==nullptr){
                head=forward;
            }
        }
    }
}

// Function to print the doubly linked list.
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    int n; cin >> n;
    Node* head = nullptr;
    for(int i=0; i<n; i++){
        int t; cin >> t;
        insert(head, t);
    }

    int key; cin >> key;
    deleteIfOccursTwice(head, key);

    printList(head);

    return 0;
}