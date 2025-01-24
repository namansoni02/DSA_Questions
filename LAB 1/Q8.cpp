    #include <bits/stdc++.h>
    using namespace std;

    typedef vector<int> vi;
    typedef vector<vi> vvi;
    typedef long long ll;

    class solution{
    public:
        int solve(vi& arr1, vi& arr2){
            // given 2 input parameters : a, b of type vector<int>
            
            int n = arr1.size(), m = arr2.size();
            // Return one integer : Size of the intersection array.
            // Complete this function now.
            int i1=0,i2=0;
            int count=0;
            while(i1<n && i2<m){
                if(arr1[i1]==arr2[i2]){
                    i1++;
                    i2++;
                    count++;
                }
                else if(arr1[i1]>arr2[i2])i2++;
                else if(arr1[i1]<arr2[i2])i1++;
            }
            return count;
            
        }
    };

    int main(){
        ios::sync_with_stdio(0); cin.tie(0);
        int a,b;

        cin>>a>>b;
        vi arr1(a,0),arr2(b,0);
        for(int i=0;i<a;i++)cin>>arr1[i];
        for(int i=0;i<b;i++)cin>>arr2[i];

        solution s;
        cout<<s.solve(arr1,arr2);

        // Write your code here
        
        // 1. Take input sizes n and m
        // 2. Instantiate 2 vector<int> objects a and b with the given sizes.
        //    hint : constructor function for class vector<int> takes 2 parameters - size and initial value.
        // 3. Use for loop to fill their values.
        
        // 4. Create a solution object and call it's member solve with the parameters.
        // 5. Display the returned value.
        
        return 0;
    }