#include <bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

typedef struct node{
    node* left; node* right;
    int id;
    node(int x){
        left = nullptr; right = nullptr;
        id = x;
    }
} node;

int max(int a, int b) {
    return (a > b) ? a : b;
}

node* levelOrderToBT(vector<int>& v){

    vector<node*> nodes(v.size(), nullptr);
    for(int i=0;i<v.size();i++) if(v[i]!=-1) nodes[i] = new node(v[i]);

    for(int i=0;i<v.size();i++){
        if(v[i]==-1) continue;
        if(2*i+1<v.size() and v[2*i+1]!=-1) nodes[i]->left = nodes[2*i+1];
        if(2*i+2<v.size() and v[2*i+2]!=-1) nodes[i]->right = nodes[2*i+2];
    }

    return nodes[0];

}
// DO NOT ALTER THE CODE ABOVE.

class Solution{
    // Add helper functions/variables here as private members
public:
    int MaxScore(node* r){
        // complete the function now.
        unordered_map<int,int> weight;
        make_weight(r,weight);
    }
    int make_weight(node* root,unordered_map<int,int>& weight){
        int sum=0;;
        if(root==nullptr)return 0;
        int a=make_weight(root->right,weight);
        int b=make_weight(root->left,weight);
        weight[root->id]=root->id+max(a,b);
        return 
    }
};

// DO NOT ALTER THE CODE BELOW.

int main(){

    int h; cin >> h;
    vector<int> v((1<<(h+1))-1,-1);
    for(int & i : v) cin >> i;

    node* root = levelOrderToBT(v);

    Solution sol;
    cout << sol.MaxScore(root);


    return 0;
}