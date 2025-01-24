#include <iostream>
#include <vector>
using namespace std;

class Stack {
private:
    vector<int> elements;

public:
    // Function to check if the stack is empty
    bool isEmpty() const {
        return elements.empty();
    }

    // Function to push an integer onto the stack
    void push(int value) {
        elements.push_back(value);
    }

    // Function to pop the top element from the stack
    int pop() {
        if (isEmpty()) {
            return -1;
        }
        int temp = elements.back();
        elements.pop_back();
        return temp;
    }

    // Function to print the elements of the stack
    void printStack() const {
        for (auto i : elements) {
            cout << i << " ";
        }
        cout << endl;
    }

    // Function to return the top element of the stack
    int top() const {
        if (isEmpty()) {
            return -1;
        }
        return elements.back();
    }

    // Recursive function to insert an element at the correct position in a sorted stack
    void sortedInsert(int value) {
        if (isEmpty() || top() <= value) {
            push(value);
            return;
        }
        int temp = pop();
        sortedInsert(value);
        push(temp);
    }

    // Recursive function to sort the given stack in ascending order
    void sortStack() {
        if (isEmpty()) {
            return;
        }
        int temp = pop();
        sortStack();
        sortedInsert(temp);
    }
};

int main() {
    int t; cin >> t;
    while (t--) {
        Stack stack;

        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            int k; cin >> k;
            stack.push(k);
        }

        // Sorting the stack
        stack.sortStack();

        stack.printStack();
    }
    return 0;
}
