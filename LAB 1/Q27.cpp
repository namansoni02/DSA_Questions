#include <iostream>
#include <vector>
using namespace std;

class solution {
public:
    vector<vector<int>> make_array(vector<vector<int>>& ans, vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            int num = arr[i];
            vector<int> temp(8, 0);

            for (int j = 0; j < 8 && num > 0; j++) {
                temp[7 - j] = num % 2;
                num = num / 2;
            }

            for (int j = 0; j < 8; j++) {
                ans[i][j] = temp[j];
            }
        }
        return ans;
    }

    int make_ans(vector<vector<int>>& ans) {
        int final_count = 0;
        for (int i = 0; i < ans.size(); i++) {
            int count = 0;
            for (int j = 0; j < 8; j++) {
                if (ans[i][j] & 1) count++;
            }
            if (count >= 5) final_count++;
        }
        return final_count;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<vector<int>> ans(n, vector<int>(8, 0));
    solution s;
    ans = s.make_array(ans, arr);

    cout << s.make_ans(ans);

    // Uncomment to print the binary representation
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < 8; j++) {
    //         cout << ans[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}
