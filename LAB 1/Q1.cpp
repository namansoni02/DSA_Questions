#include <iostream>
#include <vector>
using namespace std;

class SquareMatrix {
private:
    int n;
    vector<vector<int>> M;
public:
    // Constructor to initialize the matrix size
    SquareMatrix(int size) : n(size) {
        // TODO: Initialize matrix storage
        vector<vector<int>> ans(n,vector<int>(n,0));
        M=ans;
    }

    // Method to input matrix elements
    void inputMatrix() {
        // TODO: Implement input logic
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>M[i][j];
            }
        }
    }

    // Method to calculate the sum of both diagonals
    int calculateDiagonalSum() const {
        // TODO: Implement diagonal sum calculation
        int ans=0;
        if(n==1){
            cout<<M[0][0];
            return 0;
        }
        for(int i=0;i<n;i++){
            ans+=M[i][i]+M[i][n-i-1];
        }
        cout<<ans;
        return 0; // Placeholder return value
    }

    // Additional methods (if any) can be added here
};

int main() {
    int n;
    cin >> n;

    // TODO: Create a SquareMatrix object
    SquareMatrix s(n);
    // TODO: Input matrix elements
     s.inputMatrix();
    // TODO: Calculate and print the diagonal sum
    s.calculateDiagonalSum();
    return 0;
}