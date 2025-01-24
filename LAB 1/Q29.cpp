#include<bits/stdc++.h>
#include<vector>
using namespace std;

class solution {
public:
    void make_binary(vector<int> &A) {
        int n=A.size();
        vector<vector<int>> ans(n,vector<int>(8,0));
        for(int i=0;i<n;i++){
            int num=A[i],index=7;
            while(num!=0){
                ans[i][index]=num%2;
                num/=2;
                index--;
            }
        }
        print_ans(ans);
        return;
    }
    
    void print_ans(vector<vector<int>> &ans) {
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<8;j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
        return ;
    }
};

int main(){
    int size1; cin>>size1;
	vector<int> A(size1);
	for (int i = 0; i < size1; i++) cin>>A[i];
    
    solution s;
    s.make_binary(A);
    
    
    
    return 0;
}