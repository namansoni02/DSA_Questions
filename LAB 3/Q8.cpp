    #include <bits/stdc++.h>
    using namespace std;

    #define print(s) cout << (s) << endl
    #define ll long long

    class Stack {
    private:
        vector<ll> arr;
    public:
        void push(ll val) {
            arr.push_back(val);
        }
        void pop() {
            if (!arr.empty()) {
                arr.pop_back();
            }
        }
        ll top() {
            if (!arr.empty()) {
                return arr.back();
            }
            return LLONG_MIN; // Handle empty stack case, using LLONG_MIN to ensure comparison works
        }
        bool empty() {
            return arr.empty();
        }
        ll size() {
            return arr.size();
        }
    };

    
    int max(int a, int b) {
        return (a > b) ? a : b;
    }

    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0); 
        cout.tie(0);

        ll n, k;
        cin >> n >> k;

        vector<ll> a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }

        Stack s;
        for (ll i = n - 1; i >= 0; i--) {
            s.push(a[i]);
        }

        if (n == 1) {
            if (k % 2 == 0) {
                print(a[0]);
            } else {
                print("-1");
            }
            return 0;
        }

        ll maxx = LLONG_MIN;
        ll count = 0;

        while(count<k){
            if(!s.empty() && s.top()>maxx && s.size()>1){
                maxx=max(s.top(),maxx);
                count++;
                s.pop();
            }
            else{
                s.pop();
                s.push(maxx);
                count+=2;
                
            }
        }

        if(s.size()==0){
            cout<<-1;
        }
        else{
            cout<<s.top();
        }

        return 0;
    }
