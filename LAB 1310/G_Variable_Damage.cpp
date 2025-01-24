//NAMAN SONI CP TEMPLATE
#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

const int modulo = 1000000001;

int mod(int n) {
    return n < 0 ? -n : n;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

unordered_map<int, long long> fact;

long long calculate_factorial(int n) {
    if (fact[n] != 0) return fact[n];
    long long ans = 1;
    for (int i = 1; i <= n; i++) {
        ans *= i;
    }
    fact[n] = ans;
    return ans;
}

long long binomial_coeff(int n, int k) {
    if (k > n) return 0;
    long long a = (fact[n] != 0) ? fact[n] : calculate_factorial(n);
    long long b = (fact[k] != 0) ? fact[k] : calculate_factorial(k);
    long long c = (fact[n - k] != 0) ? fact[n - k] : calculate_factorial(n - k);
    return a / (b * c);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int z;
        cin >> z;
        vector<int> n(z), k(z);
        
        for (int i = 0; i < z; i++) {
            cin >> n[i];
        }
        for (int i = 0; i < z; i++) {
            cin >> k[i];
        }

        for (int i = 0; i < z; i++) {
            long long ans = binomial_coeff(n[i] - 1, k[i]) + binomial_coeff(n[i] - 1, k[i] - 1);
            cout << ans << endl;
        }
    }
    return 0;
}
