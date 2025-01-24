    #include <bits/stdc++.h>
    using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

// Function to create a new tree node
TreeNode* newNode(int value) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = value;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

// Function to build a binary tree from an array
TreeNode* buildTreeFromArray(int arr[], int index, int size) {
    if(index>=size){
        return nullptr;
    }
    TreeNode* node=newNode(arr[index]);
    node->left=buildTreeFromArray(arr,2*index+1,size);
    node->right=buildTreeFromArray(arr,2*index+2,size);
    return node;
}

// Function to check if two binary trees are identical
bool areIdentical(TreeNode* root1, TreeNode* root2) {
    // Implement the function here
    if(root1->data== root2->data){
        return (root1->left, root2->left)&&(root1->right, root2->right);
    }
    return false;
}

// Function to build a binary tree from a string in the array format
TreeNode* buildTreeFromArrayString(const string& str,int index) {
    // Implement the function here
    if(index>=str.size()){
        return nullptr;
    }
    TreeNode* node=newNode(str[index]-'0');
    node->left=buildTreeFromArrayString(str,2*index+1);
    node->right=buildTreeFromArrayString(str,2*index+2);
    return node;
}
void freememory(TreeNode*root){
    if(root==nullptr)return;
    freememory(root->left);
    freememory(root->right);
    delete root;
    return;
}
int main() {
    // Get the array input for the first tree from the user
    string input1;
    getline(cin, input1);

    // Create binary tree from the first input
    TreeNode* root1 = buildTreeFromArrayString(input1,0);

    // Get the array input for the second tree from the user
    string input2;
    getline(cin, input2);

    // Create binary tree from the second input
    TreeNode* root2 = buildTreeFromArrayString(input2,0);

    // Check if the trees are identical
    if (areIdentical(root1, root2)) {
        cout << "1"; // 1 for identical
    } else {
        cout << "0"; // 0 for not identical
    }

    // Free allocated memory
    freememory(root1);
    freememory(root2);
    // Implement freeing memory here

    return 0;
}