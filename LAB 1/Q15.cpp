#include <iostream>
#include <vector>
using namespace std;

class solution {
public:
    vector<vector<int>> solve(int n, int m, vector<vector<int>>& ans) {
        vector<vector<int>> arr(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int sum = 0;
                for (int k = j + 1; k < m; k++) {
                    sum += ans[i][k];
                }
                arr[i][j] = sum;
            }
        }
        return arr;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> ans(n, vector<int>(m, 0));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> ans[i][j];
        }
    }

    solution s;
    vector<vector<int>> arr = s.solve(n, m, ans);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
