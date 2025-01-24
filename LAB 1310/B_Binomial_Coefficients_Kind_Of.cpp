//NAMAN SONI CP TEMPLATE
#include <bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

const int modulo=1000000007;

int mod(int n){
    return n<0 ? -n:n;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}
int min(int a, int b) {
    return (a < b) ? a : b;
}
unordered_map<int,int> fact;

long long calculate_factorial(int n){
    long long ans=1;
    for(int i=1;i<=n;i++){
        ans*=i;
    }
    if(fact[n]!=0){
        fact[n]=ans;
    }
    return ans;
}

long long binomial_coeff(int n,int k){
    int a,b,c;
    if(k<0)return 0;
    if(k==0)return 1;
    if(n>0 && k==1)return n;
    return binomial_coeff(n,k-1)+binomial_coeff(n-1,k-1);
}


int main() {
	    int z;
	    cin>>z;
	    vector<int> n(z,0),k(z,0);
	    int temp;
	    for(int i=0;i<z;i++){
	        cin>>temp;
	        n.push_back(temp);
	    }
        for(int i=0;i<z;i++){
	        cin>>temp;
	        k.push_back(temp);
	    }

        for(int i=0;i<z;i++){
            int ans=(binomial_coeff(n[i],k[i]-1)%modulo+binomial_coeff(n[i]-1,k[i]-1)%modulo)%modulo;
            cout<<ans<<endl;
        }

	    	    
	
	return 0;

}
