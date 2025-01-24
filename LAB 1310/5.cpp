#include <bits/stdc++.h>
using namespace std;
class AliceAndBobTwo {
public:
vector<int> arr;
void take_input(){
    int n=0;
    cin>>n;
    vector<int> nums(n,0);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    this->arr=nums;
}
void gameSolver() {
// Add your code here
    sort(arr.begin(),arr.end());
    int mid=arr.size()/2;
    cout<<arr[mid]<<endl;
}
};
int main() {
// Add your code here
int t=0;
cin>>t;
while(t--){
    AliceAndBobTwo s;
    s.take_input();
    s.gameSolver();
}
return 0;
}