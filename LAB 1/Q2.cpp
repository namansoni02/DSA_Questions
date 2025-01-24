#include <iostream>
using namespace std;
class solution{
    public:
int grid(int n ){
    // Write your logic here
    if(n==0)return 1;
    if(n<0)return 0;
    int ans=0;
    if(n>=4){
        ans+=grid(n-4);
    }
    if(n>=1){
        ans+=grid(n-1);
    }
    return ans;
    // return the ans for n
}
};

int main(){
    // There's no need to change this
    int n; cin>>n;
    solution s;
    cout<<s.grid(n);
}