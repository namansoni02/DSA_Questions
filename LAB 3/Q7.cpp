#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class Stack {
private:
    Node* head;

public:
    Stack() {
        head = nullptr;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
    }

    void pop() {
        if (isEmpty()) {
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    int top() {
        if (isEmpty()) {
            return -1;
        }
        return head->data;
    }

    void printStack() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack stack;
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        if (x == 1) {
            int k;
            cin >> k;
            stack.push(k);
        }
        else if (x == 2) {
            stack.pop();
        }
        else if (x == 3) {
            cout << stack.top() << endl;
        }
        else {
            stack.printStack();
        }
    }
    return 0;
}
