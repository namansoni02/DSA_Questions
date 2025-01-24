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
    void setElements(){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) cin >> M[i][j];
        }
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
        if(mat.n==1){
            for(int i=0;i<(mat.m);i++){
            ans += mat.M[0][i];         
        }
        return ans;
        }
        if(mat.m==1){
            for(int i=0;i<(mat.n);i++){
            ans += mat.M[i][0];         
        }
        return ans;
        }
        for(int i=0;i<(mat.m);i++){
            ans += mat.M[0][i];         
            ans += mat.M[mat.n-1][i];  
        }
        for(int i=1;i<(mat.n)-1;i++){
            ans += mat.M[i][(mat.m)/2];   
        }
        return ans;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    matrix mat(n, m);
    mat.setElements();  
    solution s;
    int result = s.solve(mat);
    cout << result << endl;  

    return 0;
}
