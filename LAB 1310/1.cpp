#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
    ll k;
    vector<ll> a;

public:
    Solution(ll damage, vector<ll> v) {
        k = damage;
        a = v;
    }

    // Complete the function.
    vector<ll> solve() {
        vector<ll> ans;
        int max_index = 0;

        // Continue until all creatures are defeated
        while (true) {
            max_index = -1;
            for (int i = 0; i < a.size(); i++) {
                if (a[i] > 0 && (max_index == -1 || a[i] > a[max_index])) {
                    max_index = i;
                }
            }

            if (max_index == -1) break;

            if (a[max_index] <= k) {
                a[max_index] = -1; 
                ans.push_back(max_index);
            } else {
                a[max_index] -= k; 
            }
        }
        
        return ans;
    }
};

// Do not change this starter code
int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    Solution S(k, a);
    vector<ll> ans = S.solve();
    for (auto i : ans) cout << i << " ";
    return 0;
}
