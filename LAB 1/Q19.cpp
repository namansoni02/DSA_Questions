#include <iostream>
#include <vector>

using namespace std;

class solution{
    public:
vector<vector<char>> fillHashPatt(int n) {
    vector<vector<char>> ans(n, vector<char>(n, ' '));
    for (int i = 0; i < n; i++) {
        ans[0][i] = '#';
        ans[n-1][i] = '#';
        ans[i][0] = '#';
        ans[i][n-1] = '#';
        ans[i][i] = '#';
        ans[i][n-i-1] = '#';
    }
    return ans;
}
};

int main() {
    int n;
    cin >> n;
    
    solution s;
    vector<vector<char>> result = s.fillHashPatt(n);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << result[i][j];
        }
        cout << endl;
    }
    
    return 0;
}
