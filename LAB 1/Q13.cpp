#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

class matrix{
public:
    int n,m;
    vvi M;
    matrix(int shape0, int shape1){
        n = shape0;
        m = shape1;
        M = vvi(n,vi(m,0));
    }
    void displayMatrix(){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) cout << M[i][j] << ' ';
            cout << '\n';
        }
    }
};

class solution{
public:
    int solve(matrix& mat){
        int ans=0;
        for(int i=0;i<mat.m;i+=2){
            for(int j=0;j<mat.n;j++){
                ans+=mat.M[j][i];
            }
        }
        return ans;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n,m; cin >> n >> m;
    matrix mat(n,m);
    
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> mat.M[i][j];

    solution sol;
    cout << sol.solve(mat);

    return 0;
}