#include <bits/stdc++.h>
using namespace std;

void make_ans(int n, int &ans, int color) {
    if (n == 0) {
        ans++;
        return;
    }

    if (color == -1) {
        make_ans(n - 1, ans, 0);
        make_ans(n - 1, ans, 1);
        make_ans(n - 1, ans, 2);
    } else if (color == 0) {
        make_ans(n - 1, ans, 1);
        make_ans(n - 1, ans, 2);
    } else if (color == 1) {
        make_ans(n - 1, ans, 0);
        make_ans(n - 1, ans, 1);
        make_ans(n - 1, ans, 2);
    } else if (color == 2) {
        make_ans(n - 1, ans, 0);
        make_ans(n - 1, ans, 1);
        make_ans(n - 1, ans, 2);
    }
}

int chess(int n) {
    int ans = 0;
    make_ans(n, ans, -1);
    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << chess(n) << endl;
    return 0;
}
