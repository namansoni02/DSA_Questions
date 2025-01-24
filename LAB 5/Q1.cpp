#include <iostream>
using namespace std;

// Node structure for the linked list
class Node {
public:
    int data;
    Node* next;

    Node(int val):data(val),next(nullptr){}
};

// Class to represent a linked list
class LinkedList {
public:
    Node* head=nullptr;
    void make_node(int val){
        //cout<<"entered"<<endl;
        Node*temp=new Node(val);
        //cout<<temp->data<<endl;
        Node*root=head;
        if(root==nullptr){
            //cout<<"head empty"<<endl;
            head=temp;
            return;
        }
        while(root->next!=nullptr){
            root=root->next;
        }
        root->next=temp;
    }
    // Function to add two linked lists representing numbers
    LinkedList add_two_numbers(LinkedList head2) {
        Node*temp1=head, *temp2=head2.head;
        LinkedList ans;
        int carry=0;
        while(temp1!=nullptr && temp2!=nullptr){
            int val=temp1->data+temp2->data+carry;
            if(val>=10){
                carry=val/10;
                val=val%10;
            }
            else carry=0;
            ans.make_node(val);
            temp1=temp1->next;
            temp2=temp2->next;
        }
        while(temp1!=nullptr){
            int val=temp1->data+carry;
            if(val>=10){
                carry=val/10;
                val=val%10;
            }
            else carry=0;
            ans.make_node(val);
            temp1=temp1->next;
        }
        while(temp2!=nullptr){
            int val=temp2->data+carry;
            if(val>=10){
                carry=val/10;
                val=val%10;
            }
            else carry=0;
            ans.make_node(val);
            temp2=temp2->next;
        }
        if(carry!=0){
            ans.make_node(carry);
        }
        return ans;
    }
    // Function to display the linked list
    void print_list() {
        Node*temp=this->head;
        while(temp!=nullptr){
            cout<<temp->data;
            temp=temp->next;
        }
    }

};

int main() {
    int num1, num2;

    // Input for two numbers
    cin >> num1 >> num2;

    // Creating linked lists for the input numbers
    LinkedList list1, list2;
    if(num1==0 && num2==0){
        cout<<0;
        return 1;
    }
    while(num1>0){
        list1.make_node(num1%10);
        num1=num1/10;
    }
    while(num2!=0){
        list2.make_node(num2%10);
        num2=num2/10;
    }
    //list1.print_list();
    // Adding the linked lists
    LinkedList result = list1.add_two_numbers(list2);

    // Displaying the result
    result.print_list();

    return 0;
}