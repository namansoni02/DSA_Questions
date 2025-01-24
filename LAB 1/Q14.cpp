#include <iostream>
#include <vector>

using namespace std;

class solution{
    public:
vector<vector<int>> spiralMatrix(int n) {
    vector<vector<int>> M(n, vector<int>(n, 0));
    int start_col = 0, top_row = 0, end_col = n - 1, bottom_row = n - 1;
    int num = 1;

    while (start_col <= end_col && top_row <= bottom_row) {
        for (int i = start_col; i <= end_col; i++) {
            M[top_row][i] = num;
            num++;
        }

        for (int i = top_row + 1; i <= bottom_row; i++) {
            M[i][end_col] = num;
            num++;
        }

        if (top_row < bottom_row) {
            for (int i = end_col - 1; i >= start_col; i--) {
                M[bottom_row][i] = num;
                num++;
            }
        }

        if (start_col < end_col) {
            for (int i = bottom_row - 1; i >= top_row + 1; i--) {
                M[i][start_col] = num;
                num++;
            }
        }

        start_col++;
        end_col--;
        top_row++;
        bottom_row--;
    }

    return M;
}
};

int main() {
    int n;
    cin >> n;
    solution s;
    vector<vector<int>> result = s.spiralMatrix(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
