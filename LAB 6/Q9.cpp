#include <iostream>
#include <vector>
using namespace std;

// Node class for the linked list
class Node {
public:
    int data;
    Node* next;

    Node(int val): data(val),next(nullptr){}
};

// LinkedList class for the main linked list operations
class LinkedList {
private:
    Node* head;
    
        int find_max(Node*head,int data){
        if(head==nullptr)return 0;
        int ans=0;
        Node*temp=head;
        while(temp!=nullptr){
            if(temp->data>data && temp->data>ans)ans=temp->data;
        }
        return ans;
    }
public:
    LinkedList() : head(nullptr) {}

    void append(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Function to calculate the greater array
    vector<int> calculateGreater(int size) { 
        vector<int> ans;
        Node*temp=head;
        while(head!=nullptr){
            int num=0;
            ans.push_back(find_max(temp->next,temp->data));
        }
        return ans;
    }

    // Function to print the linked list
    void printList() {
        Node*temp=head;
        while(temp!=nullptr){
            cout<<temp->data<<" ";
        }
    }
};

int main() {
    int size;
    cin >> size;

    LinkedList list;

    // Input the elements of the linked list
    for (int i = 0; i < size; i++) {
        int data;
        cin >> data;
        list.append(data);
    }

    // Calculate the greater array
    vector<int> greater = list.calculateGreater(size);

    // Output the greater array
    for (int i = 0; i < size; i++) {
        cout << greater[i] << " ";
    }
    cout << endl;

    return 0;
}