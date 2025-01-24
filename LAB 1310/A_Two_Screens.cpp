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
	    string a,b;
        cin>>a>>b;
        int i=0;
        int n=a.size(),m=b.size();
        int x=min(n,m);
        while(i<x && a[i]==b[i]){
            i++;
        }
        int ans=0;
        if(i!=0)
        ans+=i+1;
        ans+=(n-i)+(m-i);
        cout<<ans<<endl;


	    	    
	}
	return 0;

}
