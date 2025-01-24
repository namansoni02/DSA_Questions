#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

class matrix {
public:
    int n;
    vvi M;

    matrix(int shape0) : n(shape0), M(vvi(n, vi(n, 0))) {}

    void displayMatrix() {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) cout << M[i][j] << ' ';
            cout << '\n';
        }
    }
};

class solution {
public:
    void printNewMatrix(matrix& mat) {
        vi row(mat.n, 0), col(mat.n, 0);

        for(int i = 0; i < mat.n; i++) {
            bool all_zero = true;
            for(int j = 0; j < mat.n; j++) {
                if(mat.M[i][j] != 0) {
                    all_zero = false;
                    break;
                }
            }
            if(all_zero) {
                row[i] = 1;
            }
        }

        for(int i = 0; i < mat.n; i++) {
            bool all_zero = true;
            for(int j = 0; j < mat.n; j++) {
                if(mat.M[j][i] != 0) {
                    all_zero = false;
                    break;
                }
            }
            if(all_zero) {
                col[i] = 1;
            }
        }

        for(int i = 0; i < mat.n; i++) {
            if(row[i] == 0) {
                for(int j = 0; j < mat.n; j++) {
                    if(col[j] == 0) {
                        cout << mat.M[i][j] << ' ';
                    }
                }
                cout << '\n';
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    matrix mat(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> mat.M[i][j];
        }
    }

    solution s;
    s.printNewMatrix(mat);

    return 0;
}
