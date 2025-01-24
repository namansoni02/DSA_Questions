//## CODE WRITTEN BY NAMAN SONI - B23CS1094 ##
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
const ll mod = 1e9+7;

class Stack{
    int top;
    vector<int> v;
    int maxSize;

public:

    Stack(int size){
        v = vector<int>(size,0);
        maxSize = size;
        top = -1;
    }

    bool isEmpty(){
        //return // single boolean expression : when is the stack empty? //
        //if the top index is negative , it means nothing is present so return true in that
        if(top<0)return true;
        else return false;
    }

    bool isFull(){
        //if the size is greater than limit , return true 
        //else return false
        if(top>=maxSize)return true;
        else return false;
        
    }

    int peek(){
        // return the element at the top
        //if top element is present then only return it
        if(top>=0){
           return v[top];
        }
        //else return it
        else return -1;
    }

    int pop(){
        if(isEmpty()) cerr << "Popping from empty stack";
        // remomove the top element and return it
        //if top element is present then only pop and return
        if(top>=0){
            int element=v[top];
            top--;
            return element;
        }
        //else return the -1
        else return -1;
    }

    //They are the part of the template and need not to be changed
    void push(int x){
        if(isFull()) cerr << "Pushing into a full stack";
        v[++top] = x;
    }

    void printWholeStack(){
        for(int i=top;i>=0;i--) cout << v[i] <<" ";
        cout<<'\n';
    }

};

ll sum_minOfSubArrays(vector<ll>& v){
    //storing the size of the array
    //needed to declare the stack
    int n = v.size();

    //declaring stack
    Stack s(n);

    //declaring two arrays to store the left and right min element indices for each element
    vector<int> l_min(n, -1), r_min(n, n);

    //fing the left min index for each element
    for (int i = 0; i < n; i++) {
        //if stack not empty or index representing element at the top of stack is greater than v[i] pop it
        while (!s.isEmpty() && v[s.peek()] > v[i]) {
            s.pop();
        }
        //if stack empty means the noo element is smaller on the left of present element
        if (!s.isEmpty()) {
            l_min[i] = s.peek();
        }
        //push the index for evaluation of upcoming elements
        s.push(i);
    }

    //making the stack empty for futhur use and save space
    while (!s.isEmpty()) {
        s.pop();
    }

    //fing the right min index for each element
    for (int i = n - 1; i >= 0; i--) {
        //if stack not empty or index representing element at the top of stack is greater than v[i] pop it
        while (!s.isEmpty() && v[s.peek()] >= v[i]) {
            s.pop();
        }
        //if stack empty means the noo element is smaller on the right of present element
        if (!s.isEmpty()) {
            r_min[i] = s.peek();
        }
        //push the index for evaluation of upcoming elements
        s.push(i);
    }
    
    //declaring variable to store the sum of min of each subarray
    ll ans = 0;

    for (int i = 0; i < n; i++) {
        //computing the number of arrays for which v[i] is minimum
        ll combinations = ((ll)(i - l_min[i]) * (r_min[i] - i)) % mod;

        //updating ans with modulo 1000000007 to avoid overflow
        ans = (ans + (v[i] * combinations) % 1000000007) % 1000000007;
    }

    //returning answer
    return ans;

}

int main() {
    
    //Declaring size of the array
    int n; cin >> n;
    //Taking input for the array
    vector<ll> v(n,0); for(int i=0;i<n;i++) cin >> v[i];

    //Printing the output of the function called
    cout << sum_minOfSubArrays(v);

    return 0;
}