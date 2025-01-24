#include <bits/stdc++.h>
using namespace std;

#define MX_SIZE 1000

class Stack {
    int top_index = -1;
    int v[MX_SIZE];

    public:
    bool isEmpty(){
    // ADD YOUR CODE
        if(top_index<0)return true;
        else return false;
    }

    /* Check if the stack is full */
    bool isFull(){
    //ADD YOUR CODE
        if(top_index>=MX_SIZE)return true;
        else return false;
    }

    /* Function to return the topmost element in the stack */
    int top(){
        // return the element at the top
        //if top element is present then only return it
        if(top_index>=0){
           return v[top_index];
        }
        //else return it
        else return -1;
    }

    /* Function to delete from the stack */
    int pop(){
    //ADD YOUR CODE
        if(top_index>=0){
            int element=v[top_index];
            top_index--;
            return element;
        }
        //else return the -1
        else return -1;
    }

    /* Function to insert into the stack */
    int push(int data){
    //ADD YOUR CODE
        if(top_index+1<MX_SIZE)v[++top_index] =data;
        else return -1;
        return 0;
    }

    void printWholeStack(){
        for(int i=top_index;i>=0;i--){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
};

bool isValid(string s) {
    // Add your code here.
    Stack st;
    int i=0;
    while (!st.isEmpty() || i < s.size()) {
    if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
        st.push(s[i]);
    } else {
        if (s[i] == ')') {
            if (st.top() == '(') st.pop();
            else return false;
        }
        if (s[i] == '}') {
            if (st.top() == '{') st.pop();
            else return false;
        }
        if (s[i] == ']') {
            if (st.top() == '[') st.pop();
            else return false;
        }
    }
    i++; // Increment the index to avoid an infinite loop
    }
  
    if (st.isEmpty()) return true;
    else return false;
}

int main() {
    // Do not change this.
    string s;

    cin>>s;

    // Check if parentheses are valid and print 1 or 0
    std::cout << (isValid(s) ? 1 : 0) << std::endl;

    return 0;
}