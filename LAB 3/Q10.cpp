#include <iostream>
#include <vector>
#include <algorithm>
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

class Collisions {
private:
    vector<int> arr;

public:
    Collisions(vector<int>& arr) {
        this->arr = arr;
    }

    vector<int> solve() {
        Stack stack;
        vector<int> ans;

        for(auto i:arr){
            if(i<0){
                stack.push(i);
                while(!stack.empty() && ans.size()!=0){
                    if(ans.back()>-stack.top()){
                        stack.pop();
                    }
                    else if(ans.back()==-stack.top()){
                        ans.pop_back();
                        stack.pop();
                    }
                    else{
                        ans.pop_back();
                    }
                }
                while(!stack.empty()){
                    ans.push_back(stack.top());
                    stack.pop();
                }
            }
            else{
                ans.push_back(i);
            }
        }

        return ans;
    }
};

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Collisions collide(arr);
    vector<int> result = collide.solve();

    for (int value : result) {
        cout << value << " ";
    }
    
    return 0;
}
