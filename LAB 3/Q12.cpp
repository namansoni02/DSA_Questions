#include <iostream>
#include <string>
#include<vector>
#include <cctype>

using namespace std;

// Node structure for the stack
struct Node {
    std::string data;
    Node* next;
};

// Stack class using a linked list
class Stack {
private:
    vector<string> elements;

public:
    void push(string value) {
        elements.push_back(value);
    }

    void pop() {
        if (!empty()) {
            elements.pop_back();
        }
    }

    string top() const {
        if (empty()) return "";
        return elements.back();
    }

    bool empty() const {
        return elements.empty();
    }

    int size() const {
        return elements.size();
    }
};

// Function to convert prefix to postfix
std::string prefixToPostfix(const std::string& prefix) {
    Stack stack;
    int i = prefix.size() - 1;
    
    stack.push(string(1, prefix[i--]));
    stack.push(string(1, prefix[i--]));

    for (int j = i; j >= 0; --j) {
        if (prefix[j] == '+' || prefix[j] == '-' || prefix[j] == '*' || prefix[j] == '/' || prefix[j] == '^') {
            string temp = "";
            temp.append(stack.top()); stack.pop();
            temp.append(stack.top()); stack.pop();
            temp.push_back(prefix[j]);
            stack.push(temp);
        }
        else {
            stack.push(string(1, prefix[j]));
        }
    }

    return stack.top();
}

int main() {
    std::string prefix;
    std::cin >> prefix;

    try {
        std::string postfix = prefixToPostfix(prefix);
        std::cout << postfix << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
