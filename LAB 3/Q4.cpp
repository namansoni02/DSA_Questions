#include <iostream>
#include <cstring>  // For strlen function
using namespace std;
#define MX_SIZE 100

class Stack {
    int top_index = -1;
    int v[MX_SIZE];

public:
    // Check if the stack is empty
    bool isEmpty() {
        // ADD YOUR CODE
        if (top_index < 0) return true;
        else return false;
    }

    /* Check if the stack is full */
    bool isFull() {
        // ADD YOUR CODE
        if (top_index >= MX_SIZE - 1) return true;
        else return false;
    }

    /* Function to return the topmost element in the stack */
    int top() {
        // return the element at the top
        // if top element is present then only return it
        if (top_index >= 0) {
            return v[top_index];
        }
        // else return it
        else return -1;
    }

    /* Function to delete from the stack */
    int pop() {
        // ADD YOUR CODE
        if (top_index >= 0) {
            int element = v[top_index];
            top_index--;
            return element;
        }
        // else return the -1
        else return -1;
    }

    /* Function to insert into the stack */
    int push(int data) {
        // ADD YOUR CODE
        if (top_index + 1 < MX_SIZE) {
            v[++top_index] = data;
            return 0;
        } else return -1;
    }

    void printWholeStack() {
        for (int i = top_index; i >= 0; i--) {
            cout << v[i] << " ";
        }
        cout << endl;
    }
};

void reverse(char* str) {
    Stack stack;
    int n = strlen(str);
    for (int i = 0; i < n; i++) {
        stack.push(str[i]);
    }
    int i = 0;
    while (!stack.isEmpty()) {
        str[i++] = stack.pop();
    }
    str[i] = '\0'; 
}

// Function to reverse a string in place
void reverseString(char* str) {
    // Type your logic here
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        std::swap(str[i], str[n - i - 1]);
    }
}

int main() {
    char input[100];
    std::cin >> input;
    reverse(input);
    std::cout << input << endl;
    return 0;
}
