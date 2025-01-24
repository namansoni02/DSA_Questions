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
        int a,b;
        int l=0,w=0;
	    while(n--){
            cin>>a>>b;
            l=max(l,a);
            w=max(w,b);
        }
        cout<<2*(l+w)<<endl;

	    	    
	}
	return 0;

}
