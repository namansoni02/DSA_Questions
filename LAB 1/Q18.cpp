#include <iostream>
#include <vector>
using namespace std;

class solution {
public:
    void solve(int n, int &ans1,int &ans2, vector<vector<int>> &mat){
        for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i >= j) {
                ans1 += mat[i][j];
            }
            if(i <= j) {
                ans2 += mat[i][j];
            }
        }
    }
    }
};

int main() {
    int n;
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n, 0));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    int ans1 = 0, ans2 = 0;
    solution s;
    s.solve(n,ans1,ans2,mat);
    
    cout << ans2 << " " << ans1;
    
    return 0;
}
