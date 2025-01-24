#include <iostream>
#include <vector>
using namespace std;

class CharacterMatrix {
private:
    int n;
    char startChar;
    vector<vector<char>> M;
public:
    CharacterMatrix(int size, char ch) : n(size), startChar(ch) {
        M = vector<vector<char>>(n, vector<char>(n, ' '));
    }

    void generateMatrix() {
        int start_col = 0, top_row = 0, end_col = n - 1, bottom_row = n - 1;
        char ch = startChar;

        while (start_col <= end_col && top_row <= bottom_row) {
            for (int i = start_col; i <= end_col; i++) {
                M[top_row][i] = ch;
            }

            for (int i = top_row; i <= bottom_row; i++) {
                M[i][end_col] = ch;
            }

            for (int i = start_col; i <= end_col; i++) {
                M[bottom_row][i] = ch;
            }

            for (int i = top_row; i <= bottom_row; i++) {
                M[i][start_col] = ch;
            }

            ch = (ch == 'z') ? 'a' : ch + 1;

            start_col++;
            end_col--;
            top_row++;
            bottom_row--;
        }
    }

    void printMatrix() const {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << M[i][j] ;
            }
            cout << endl;
        }
    }
};

int main() {
    int n;
    char startChar;

    cin >> n;
    cin >> startChar;

    CharacterMatrix mat(n, startChar);
    mat.generateMatrix();
    mat.printMatrix();

    return 0;
}
