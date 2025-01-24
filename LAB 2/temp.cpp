class Solution {
public:
    void dfs(int i,map<int,vector<int>> mapping,vector<int>&ans,vector<bool> &check){
        if(mapping[i].size()==0){
            ans.push_back(i);
            return;
        }
        for(int j=0;j<mapping[i].size();j++){
            if(check[mapping[i][j]]){
                dfs(mapping[i][j],mapping,ans,check);
            }
        }
        ans.push_back(i);
        return;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        map<int,vector<int>> mapping;
        vector<int> ans;
        vector<int>in_degree(numCourses,0);
        if(numCourses==1){
            ans.push_back(0);
            return ans;
        }
        for(auto i:prerequisites){
            mapping[i[1]].push_back(i[0]);
            in_degree[i[0]]++;
        }
        // for(auto i:mapping){
        //     cout<<i.first<<"::";
        //     for(int j=0;j<i.second.size();j++){
        //         cout<<i.second[j]<<" ";
        //     }
        //     cout<<endl;
        // }
        vector<bool> check(numCourses,false);
        for(int i=0;i<numCourses;i++){
            if(in_degree[i]==0){
            dfs(i,mapping,ans,check);
            break;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};