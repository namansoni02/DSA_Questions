//NAMAN SONI CP TEMPLATE
#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int mod(int n) {
    return n < 0 ? -n : n;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;

        long long ans = 0;
        map<long long, bool> done;
        map<long long, vector<long long>> mp;

        // Reading input and preparing the map
        for (int i = 1; i <= n; ++i) {
            long long a;
            cin >> a;
            if (i > 1) mp[a].push_back(1);
        }

        // DFS function
        function<void(long long)> dfs = [&](long long len) {
            done[len] = true;
            ans = max(ans, len);

            for (auto i : mp[len - n]) {
                if (!done[len + 1 - 1]) {
                    dfs(len + 1 - 1);
                }
            }
        };

        // Start DFS
        dfs(n);

        // Output the result
        cout << ans << '\n';
        
        // Clearing the maps for the next test case
        mp.clear();
        done.clear();
    }

    return 0;
}
