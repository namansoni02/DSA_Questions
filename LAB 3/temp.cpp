#include <bits/stdc++.h>
using namespace std;
#define elif else if
#define print(s) cout<<(s)<<endl
#define ll long long

class Stack {
private:
    vector<ll> arr;
public:
    void push(ll val) { arr.push_back(val); }
    void pop() { if (!arr.empty()) arr.pop_back(); }
    ll top() { return arr.empty() ? -1 : arr.back(); }
    ll size() { return arr.size(); }
    bool empty() { return arr.empty(); }
};

int main() {
    int n, k;
    cin >> n >> k;
    
    Stack s;
    vector<ll> arr(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    // Push elements in the given order (leftmost on top)
    for (int i = 0; i < n; i++) {
        s.push(arr[i]);
    }
    
    ll max_elem = LLONG_MIN;
    Stack temp;
    int ops = 0;
    
    // Perform k operations
    while (ops < k) {
        if (s.empty() && temp.empty()) {
            print(-1);
            return 0;
        }
        
        if (!s.empty()) {
            ll top = s.top();
            s.pop();
            max_elem = max(max_elem, top);
            temp.push(top);
        } else {
            s.push(temp.top());
            temp.pop();
        }
        ops++;
    }
    
    // Find the maximum possible top element
    ll ans = s.empty() ? temp.top() : max(s.top(), max_elem);
    
    print(ans);
    return 0;
}