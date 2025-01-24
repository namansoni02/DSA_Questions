#include <iostream>
#include <vector>

using namespace std;
class sol{
    public:
void spiralMatrix(const vector<vector<int>>& result, int n, int m) {
    int start_col = 0, top_row = 0, end_col = m - 1, bottom_row = n - 1;

    while (start_col <= end_col && top_row <= bottom_row) {
        for (int i = start_col; i <= end_col; i++) {
            cout << result[top_row][i] << " ";
        }
        top_row++;

        for (int i = top_row; i <= bottom_row; i++) {
            cout << result[i][end_col] << " ";
        }
        end_col--;

        if (top_row <= bottom_row) {
            for (int i = end_col; i >= start_col; i--) {
                cout << result[bottom_row][i] << " ";
            }
            bottom_row--;
        }

        if (start_col <= end_col) {
            for (int i = bottom_row; i >= top_row; i--) {
                cout << result[i][start_col] << " ";
            }
            start_col++;
        }
    }
}
};
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> result(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> result[i][j];
        }
    }
    sol s;
    s.spiralMatrix(result, n, m);
    return 0;
}
