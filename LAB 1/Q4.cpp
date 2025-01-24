#include <iostream>
#include <vector>
using namespace std;

int arr[101][101];

class solution {
    public:
void col_wise_sum_of_transpose(int r, int c) {
    vector<int> ans(r, 0);  

    // Calculate column-wise sum of the transpose
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            ans[i] += arr[i][j];  
        }
    }

    // Print the array
    for(int i = 0; i < r; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}
};

int main() {
    // Get the rows and columns
    int a, b;
    cin >> a >> b;
    
    // Get the matrix
    for(int i = 0; i < a; i++) {
        for(int j = 0; j < b; j++) {
            cin >> arr[i][j];
        }
    }
    
    // Call the function
    solution s;
    s.col_wise_sum_of_transpose(a, b);
   
    return 0;
}