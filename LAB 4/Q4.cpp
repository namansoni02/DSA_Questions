#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
    
    
    
};

TreeNode* buildTree(const std::vector<int>& nodes) {
    if (nodes.empty()) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(nodes[0]);
    std::queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* current = q.front();
        q.pop();

        if (nodes[i] != -1) {
            current->left = new TreeNode(nodes[i]);
            q.push(current->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != -1) {
            current->right = new TreeNode(nodes[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

bool isPathSum(TreeNode* root, int targetSum,int current_sum) {
    if(root==nullptr){
        if(current_sum==targetSum)return true;
        else return false;
    }
    

    bool a=isPathSum(root->left, targetSum,current_sum+root->value);
    bool b=isPathSum(root->right, targetSum,current_sum+root->value);
    
    if(a || b)return true;
    else return false;
}

int main() {
    int n, targetSum;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cin >> targetSum;

    TreeNode* root = buildTree(arr);

    bool result = isPathSum(root, targetSum,0);
    cout << (result ? "true" : "false")<<"\n";

    delete root;

    return 0;
}