#include <iostream>
#include <vector>
using namespace std;

class SquareMatrix {
private:
    int n;
    vector<vector<int>> M;

public:
    SquareMatrix(int size) : n(size) {
        M = vector<vector<int>>(n, vector<int>(n, 0));
    }

    void inputMatrix() {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
    }

    void printLowerTriangularMatrix() const {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i > j) {
                    cout << M[i][j] << " ";
                } else {
                    cout << 0 << " ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    int n;
    cin >> n;

    SquareMatrix mat(n);
    mat.inputMatrix();
    mat.printLowerTriangularMatrix();

    return 0;
}
