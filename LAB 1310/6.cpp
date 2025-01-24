#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class Juice {
private:
    int n, k;
    vector<int> arr;

public:
    Juice(int n, int k, vector<int>& arr) {
        this->n = n;
        this->k = k;
        this->arr = arr;
    }

    long long solve() {
        ll sum = 0;
        if (k >= n) {
            for (int i = 0; i < n; i++) {
                sum += arr[i];
            }
            return sum;
        } else {
            sort(arr.begin(), arr.end());
            sum = arr[n - 1]; // Maximum jug
            for (int i = 1; i <= k; i++) { // Adding k largest values
                sum += arr[n - i];
            }
            return sum - arr[0]; // Subtracting the minimum jug
        }
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    Juice juiceClass(n, k, arr);
    cout << juiceClass.solve() << "\n";
    return 0;
}
