#include <iostream>
#define MAX_SIZE 100  // Define the maximum size of the array

using namespace std;

// Class representing two stacks using a single array
class TwoStacks {
    int arr[MAX_SIZE];
    int top1;  // Top for the first stack
    int top2;  // Top for the second stack

public:
    // Constructor to initialize the two stacks
    TwoStacks() {
        initialize();
    }

    // Function to initialize the two stacks
    void initialize() {
        top1 = -1;
        top2 = MAX_SIZE;
    }

    // Function to push an element onto the first stack
    void push1(int x) {
        // Ensure that you check for overflow
        if (top1 + 1 < top2) {
            arr[++top1] = x;
        } else {
            cout << "Stack-1 Overflow" << endl;
        }
    }

    // Function to push an element onto the second stack
    void push2(int x) {
        // Ensure that you check for overflow
        if (top2 - 1 > top1) {
            arr[--top2] = x;
        } else {
            cout << "Stack-2 Overflow" << endl;
        }
    }

    // Function to pop an element from the first stack
    int pop1() {
        // Ensure that you check for underflow
        if (top1 >= 0) {
            return arr[top1--];
        } else {
            cout << "Stack-1 Underflow" << endl;
            return -1;
        }
    }

    // Function to pop an element from the second stack
    int pop2() {
        // Ensure that you check for underflow
        if (top2 < MAX_SIZE) {
            return arr[top2++];
        } else {
            cout << "Stack-2 Underflow" << endl;
            return -1;
        }
    }

    // Function to print the elements of both stacks
    void printBoth() {
        for (int i = 0; i <= top1; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        
        for (int i = MAX_SIZE-1; i >= top2; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Main function
int main() {
    TwoStacks ts;
    ts.initialize();

    int n1, n2, x;

    cin >> n1;
    for (int i = 0; i < n1; i++) {
        cin >> x;
        ts.push1(x);
    }

    cin >> n2;
    for (int i = 0; i < n2; i++) {
        cin >> x;
        ts.push2(x);
    }

    // Perform a series of stack operations
    ts.printBoth();
    cout<<ts.pop1()<<endl;
    cout<<ts.pop2()<<endl;
    ts.printBoth();

    return 0;
}
