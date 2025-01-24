#include <iostream>
#include<map>
#include<vector>
using namespace std;

class Stack {
private:
    vector<int> elements;

public:
    void push(int value) {
        elements.push_back(value);
    }

    void pop() {
        if (!empty()) {
            elements.pop_back();
        }
    }

    int top() const {
        if (empty()) return -1;
        return elements.back();
    }

    bool empty() const {
        return elements.empty();
    }

    int size() const {
        return elements.size();
    }
};

void infixToPostfix(const char* infix, char* postfix) {
    Stack line;
    int i=0;
    int j=0;
    map<char,int> mapping;
    mapping['^']=3;mapping['*']=2;mapping['/']=2;mapping['+']=1;mapping['-']=1;
    while(infix[i]!='\0'){
        char c=infix[i];
        if(c>='A' && c<='Z'){
            postfix[j]=c;
            j++;
        }
        else if(c=='^' || c=='('){
            line.push(c);
        }
        else if(c==')'){
            while(!line.empty() && line.top()!='('){
                postfix[j]=line.top();
                j++;
                line.pop();
            }
            line.pop();
        }
        else if(mapping[c]>mapping[line.top()]){
            line.push(c);
        }
        else{
            while(!line.empty() && mapping[c]<=mapping[line.top()]){
                postfix[j]=line.top();
                j++;
                line.pop();
            }
            line.push(c);
        }
        i++;
    }
    while(!line.empty()){
        postfix[j]=line.top();
        line.pop();
        j++;
    }
    
}

int main() {
    char infix[100];
    char postfix[100];

    cin >> infix;

    infixToPostfix(infix, postfix);

    cout << postfix << "\n";

    return 0;
}