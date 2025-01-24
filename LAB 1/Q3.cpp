#include<bits/stdc++.h>
using namespace std;

class matrixClass {
public:
    int n, m;
    vector<vector<int>> M;

    matrixClass(int shape0, int shape1, vector<vector<int>> matrix) {
        n = shape0;
        m = shape1;
        M = matrix;
    }

    void displayMatrix() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) cout << M[i][j] << ' ';
            cout << endl;
        }
    }

    void matrixConverter() {
        vector<vector<int>> ans(6, vector<int>(6, 0));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                ans[i][j] = M[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = i; j < m; j++) {
                ans[i][j + 3] = M[i][j];
            }
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 6; j++) {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    vector<vector<int>> matrix(3, vector<int>(3, 0));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> matrix[i][j];
        }
    }

    matrixClass M(3, 3, matrix);
    M.matrixConverter();
    return 0;
}
