#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

class matrix {
public:
    int n, m;
    vvi M;
    
    matrix(int shape0, int shape1) {
        n = shape0;
        m = shape1;
        M = vvi(n, vi(m, 0));
    }

    void displayMatrix() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << M[i][j] << ' ';
            }
            cout << '\n';
        }
    }
};

class solution {
public:
    int solve(matrix& mat) {
        int ans = 0;
        int centerRow = mat.n / 2;
        int centerCol = mat.m / 2;

        // Sum the center row
        for (int i = 0; i < mat.m; i++) {
            ans += mat.M[centerRow][i];
        }

        // Sum the center column
        for (int i = 0; i < mat.n; i++) {
            ans += mat.M[i][centerCol];
        }

        // Subtract the center element (since it's added twice)
        ans -= mat.M[centerRow][centerCol];
        
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    matrix mat(n, m);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat.M[i][j];
        }
    }

    solution sol;
    cout << sol.solve(mat);

    return 0;
}
