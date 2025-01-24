#include <iostream>
#include <vector>
using namespace std;

class Matrix {
public:
    int n, m;
    vector<vector<int>> M;

    Matrix(int rowsize, int colsize) {
        n = rowsize;
        m = colsize;
        M = vector<vector<int>>(n, vector<int>(m, 0));
    }

    void printMatrix() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << M[i][j]<<" ";
            }
            cout << endl;
        }
    }

    void add_k_matrix(int k, int row1, int col1, int row2, int col2) {
        int i1 = max(0, min(row1, row2));
        int i2 = min(n - 1, max(row1, row2));
        int j1 = max(0, min(col1, col2));
        int j2 = min(m - 1, max(col1, col2));

        for (int i = i1; i <= i2; i++) {
            for (int j = j1; j <= j2; j++) {
                M[i][j] += k;
            }
        }
    }
};

int main() {
    int n, m;
    
    cin >> n >> m;
    Matrix mat(n, m);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat.M[i][j];
        }
    }

    int k, row1, col1, row2, col2;
    cin >> k >> row1 >> col1 >> row2 >> col2;
    
    mat.add_k_matrix(k, row1, col1, row2, col2);
    mat.printMatrix();
    
    return 0;
}
