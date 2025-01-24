#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    unordered_map<int, bool> covered;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        covered[nums[i]] = false;
    }

    sort(nums.begin(), nums.end());

    int rounds = 0, curr = 1;

    while (true) {
        rounds++;
        bool allCovered = true;
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (!covered[nums[i]] && nums[i] == curr) {
                covered[nums[i]] = true;
                count++;
            }
        }
        
        if (count == n) break;

        curr++;
    }

    cout << rounds << endl;

    return 0;
}
