#include<bits/stdc++.h>
using namespace std;

#define rows 100
#define cols 100

class solution{
    public:
void compute_matrix(vector<vector<int>>& arr, int n, int m){
    vector<vector<int>> ans(n, vector<int>(m, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int sum = 0;

            for(int k = j + 1; k < m; k++){
                sum += arr[i][k];
            }

            for(int k = i + 1; k < n; k++){
                for(int l = 0; l < m; l++){
                    sum += arr[k][l];
                }
            }

            ans[i][j] = sum;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}
};

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m, 0));
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    solution s;
    s.compute_matrix(arr, n, m);

    return 0;
}
