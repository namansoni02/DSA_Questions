#include <iostream>
#include <vector>
#include <iomanip> 
using namespace std;

class Matrix{
    private:
    
    public:
    int n, m;
    vector<vector<int>> M;
    
    Matrix(int rowsize, int colsize){
        n = rowsize;
        m = colsize;
        M = vector<vector<int>>(n, vector<int>(m, 0));
    }

    void print_averages(int row, int col){
    // Complete the function here
        double row_avg=0,col_avg=0;
        for(int i=0;i<m;i++)row_avg+=M[row][i];
        for(int i=0;i<n;i++)row_avg+=M[i][col];
        row_avg/=m;
        col_avg/=n;
        cout<<fixed<<setprecision(2)<<row_avg<<col_avg;
        
        return;
    }
};


int main(){
    int n, m;
    
    // Input n and m here
    cin>>n>>m;
    
    Matrix mat(n,m);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat.M[i][j];
        }
    }
    
    int row, col;
    cin>>row>>col;
    // Input matrix and row and col here
    
    mat.print_averages(row, col);
    
    return 0;
}