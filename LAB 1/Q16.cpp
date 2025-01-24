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

    void setElements() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
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
    void solve(matrix& mat) {
        int n = mat.n, m = mat.m;
        vvi ans = mat.M;

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < m - 1; k++) {
                for (int l = 0; l < m - 1; l++) {
                    if (ans[i][l] > ans[i][l + 1]) {
                        swap(ans[i][l], ans[i][l + 1]);
                    }
                }
            }
        }

        mat.M = ans;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    matrix mat(n, m);
    mat.setElements();

    solution s;
    s.solve(mat);
    mat.displayMatrix();

    return 0;
}
