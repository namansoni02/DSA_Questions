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
        //write your code here, return the answer in the end.
        if (mat.n == 0 || mat.m == 0) return 0;  // Handle empty matrix case
        if (mat.m == 1 && mat.n == 1) return mat.M[0][0];
        if (mat.M[0][0] == 1 && mat.M[0][mat.m-1] == 1 && mat.M[mat.n-1][0] == 1 && mat.M[mat.n-1][mat.m-1] == 1){           return 1;
        }
        else return 0;
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
    // 1. Instantiate a matrix object with the input shape taken.
    // 2. use for loop to set it's elements.
    // 3. Create a solution object and call its member function solve.
    // 4. print the value returned by the member solve.

    return 0;
}