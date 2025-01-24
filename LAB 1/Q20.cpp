#include <iostream>
#include <vector>
using namespace std;

class sol {
public:
    int check(vector<vector<int>>& ans, int n, int m) {
        if (n == 0 || m == 0) return -1;  // Return -1 for empty matrix
        if (n == 1 && m == 1) return ans[0][0];  // Special case for 1x1 matrix
        
        bool isZeroMatrix = true;
        bool isOneMatrix = true;
        bool isIdentityMatrix = true;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (ans[i][j] != 0) isZeroMatrix = false;
                if (ans[i][j] != 1) isOneMatrix = false;
                if ((i == j && ans[i][j] != 1) || (i != j && ans[i][j] != 0)) isIdentityMatrix = false;
                
                if (!isZeroMatrix && !isOneMatrix && !isIdentityMatrix) return -1;  // Early exit if no condition is met
            }
        }
        
        if (isZeroMatrix) return 0;
        if (isOneMatrix) return 1;
        if (isIdentityMatrix && n == m) return 2;
        
        return -1;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> ans(n, vector<int>(m, 0));
    
    sol s;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> ans[i][j];
        }
    }
    
    cout << s.check(ans, n, m);
    
    return 0;
}
