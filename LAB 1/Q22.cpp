#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector<vector<char>> convertTo2DArray(const string& str) {
    int max_count = 0, count = 0, n = 0;
    vector<vector<char>> ans;

    for (char ch : str) {
        if (ch != ' ') {
            count++;
        } else if (ch == ' ' && count > 0) {
            max_count = max(max_count, count);
            count = 0;
            n++;
        }
    }
    if (count > 0) {
        max_count = max(max_count, count);
        n++;
    }

    ans.resize(n, vector<char>(max_count, ' '));

    int row = 0, col = 0;
    for (char ch : str) {
        if (ch != ' ') {
            ans[row][col] = ch;
            col++;
        } else if (ch == ' ') {
            if (col > 0) {
                row++;
                col = 0;
            }
        }
    }

    return ans;
}

int main() {
    string input;
    getline(cin, input);

    vector<vector<char>> result = convertTo2DArray(input);

    for (const auto& row : result) {
        cout << "[";
        for (size_t j = 0; j < row.size(); ++j) {
            cout << "'" << row[j] << "' ";
        }
        cout << "]" << endl;
    }

    return 0;
}
