// Write a program to find spike points in a linked list. A spike point can be classified as either an up-spike or a down-spike:
// Up-spike: Occurs when both the predecessor and successor values are lower than the current node's value.
// Down-spike: Occurs when both the predecessor and successor values are higher than the current node's value.
// The task is to determine the total number of up-spikes and down-spikes in the linked list.

// Input Format:
// The first line contains an integer n, representing the number of elements in the linked list.
// The second line contains n space-separated integers, representing the elements of the linked list.

// Output Format:
// Print two integers: the total number of up-spikes and the total number of down-spikes.

// Sample Test Case:
// Input:
// 7
// 5 3 6 2 8 1 4

// Output:
// 2 1

// Explanation:
// Up-spikes: 6 (predecessor 3, successor 2), and 8 (predecessor 2, successor 1).
// Down-spike: 2 (predecessor 6, successor 8).

#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int val;
    node* next;
    node(int v = 0, node* nxt = NULL) {
        val = v;
        next = nxt;
    }
};

class LinkedList {
public:
    node* head;
    LinkedList(node* h = NULL) {
        head = h;
    }

    void insert(int val) {
        node* newNode = new node(val);
        if (head == NULL) {
            head = newNode;
        } else {
            node* curr = head;
            while (curr->next != NULL) {
                curr = curr->next;
            }
            curr->next = newNode;
        }
    }

    pair<int, int> findSpikes() {
        int upSpikes = 0, downSpikes = 0;
        if(head==nullptr || head->next==nullptr || head->next->next==nullptr){
            return make_pair(0,0);
        }
        // Complete this function to count upSpikes and downSpikes.
        node * ptr1=head, *ptr2=head->next, *ptr3=ptr2->next;
        while(ptr1!=nullptr && ptr2!=nullptr && ptr3!=nullptr){
            if(ptr1->val < ptr2->val && ptr2->val>ptr3->val){
                upSpikes++;
            }
            else if(ptr1->val > ptr2->val && ptr2->val<ptr3->val){
                downSpikes++;
            }
            ptr1=ptr2;
            ptr2=ptr3;
            ptr3=ptr3->next;
        }
        

        return {upSpikes, downSpikes};
    }
};

int main() {
    LinkedList list;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        list.insert(val);
    }

    pair<int, int> spikes = list.findSpikes();
    cout << spikes.first << " " << spikes.second << endl;

    return 0;
}