//NAMAN SONI CP TEMPLATE
#include <bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

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
	    for(int i=0;i<n;i++){
	        cin>>temp;
	        nums.push_back(temp);
	    }
        
        int ans=0;
	    for(int i=0;i<n-1;i++){
            map<int,int> frequency;
            int count=0,num=-1;
             int x=0;
            if(nums[i]!=0){
            for(int j=i;j<n;j++){
                if(nums[i]==nums[j])ans++;
            }
            }
            else{
               for(int j=i;j<n;j++){
                frequency[nums[j]]++;
                x=max(x,frequency[nums[j]]);
            }
            ans+=x;
            }
        }
        cout<<ans<<endl;    	    
	}
	return 0;

}
