#include <iostream>
#include <vector>

using namespace std;

int IndicesIncrementAndEvenCounter(const vector<vector<int>>& index, int n, int m) {
    if(n==0 || m==0)return 0;
    int evenCount = 0;
    vector<vector<int>> ans(n, vector<int>(m, 0));
    
    for (const auto& indices : index) {
        if (indices[0] >= 0 && indices[0] < n) { 
            for (int i = 0; i < m; i++) {
                ans[indices[0]][i]++;
            }
        }
        if (indices[1] >= 0 && indices[1] < m) { 
            for (int i = 0; i < n; i++) {
                ans[i][indices[1]]++;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (ans[i][j] % 2 == 0) {
                evenCount++;
            }
        }
    }
    
    return evenCount;
}

int main() {
    int n, m;
    vector<vector<int>> index;
    int index_len;
    
    cin >> n >> m >> index_len;
    for (int i = 0; i < index_len; i++) {
        vector<int> temp(2, 0);
        cin >> temp[0] >> temp[1];
        
            index.push_back(temp);
        
    }
    int evenCount = IndicesIncrementAndEvenCounter(index, n, m);
    cout << evenCount;
    return 0;
}
