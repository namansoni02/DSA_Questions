#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned long long ull;

ll a[200005];

void solve() {
    int n;
    cin >> n;

    ll ans = 1e9; // Set a large initial value for ans
    bool flag = 1;

    vector<int> h(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        ll sum = i;

        for (int j = i + 1; j < n; ++j) {
            if (a[j] > a[i]) {
                sum++;
            }
        }

        ans = min(ans, sum); // Keep track of the minimum sum
    }

    cout << ans << '\n';
}

int main() { // main should return int

    int T = 1; 
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}
