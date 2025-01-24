#include <iostream>
#include <vector>
using namespace std;
// Definition for a binary tree node
class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};
int mod(int n){
    return n<0 ? -n:n;
}
class BinaryTree {
    public:
    TreeNode* root;
   TreeNode* make_tree(const vector<int> &arr, int i) {
    if (i >= arr.size() || arr[i] == -1) {
        return nullptr;
    }
    
    TreeNode* temp = new TreeNode(arr[i]);
    
    temp->left = make_tree(arr, 2 * i + 1);
    temp->right = make_tree(arr, 2 * i + 2);
    
    return temp;
    }
    int height(TreeNode*root) const{
        if(root==0)return 0;

        int left_height=height(root->left);
        int right_height=height(root->right);
        return left_height+right_height+1;
    }

    bool isBalanced(TreeNode*root) const {
        if(root==nullptr)return true;
        int left_height=height(root->left);
        int right_height=height(root->right);

        if(mod(left_height-right_height)<=1)return true;
        else return false;
    }
    
};

int main() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    BinaryTree tree;
    tree.root=tree.make_tree(arr,0);
    std::cout << (tree.isBalanced(tree.root) ? "true" : "false") << std::endl;

    return 0;
}