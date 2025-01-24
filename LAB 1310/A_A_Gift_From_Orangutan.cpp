//NAMAN SONI CP TEMPLATE
#include <bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>

using namespace std;
int mod(int n){
    return n<0 ? -n:n;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}
int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> nums;
	    int temp;
        int min=INT_MAX;
        int max=INT_MIN;
	    for(int i=0;i<n;i++){
	        cin>>temp;
	        nums.push_back(temp);
	    }
        sort(nums.begin(),nums.end());
        temp=0;
        for(int i=0;i<n-1;i++){
            temp+=nums[n-1]-nums[i];
        }
        cout<<temp<<endl;
        
    	    
	}
	return 0;

}
