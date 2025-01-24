#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int c){
        val=c;
        left=nullptr;
        right=nullptr;
    }
};

// Function to find the Kth smallest element in a BST.
int kthSmallest(struct TreeNode* root, int k) {
    // Implement the function here
     if (root == nullptr) return -1;

    vector<int> elements;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        elements.push_back(node->val);
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }

    sort(elements.begin(), elements.end()); 
    return (k > 0 && k <= elements.size()) ? elements[k - 1] : -1; 
}

// Function to insert a value into the BST.
struct TreeNode* insert(struct TreeNode* root, int val) {
    // Implement the function here
    if (!root) return new TreeNode(val);
    if (val < root->val){
        root->left = insert(root->left, val);
    } 
    else{
        root->right = insert(root->right, val);
    }
    return root;
}


// Function to take level order input from the user to construct the BST.
struct TreeNode* constructBST() {
    // Implement the function here
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    TreeNode* root = NULL;
    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }
    return root;
}

// Example usage
int main() {
    // Construct the BST
    struct TreeNode* root = constructBST();

    // Get the value of K from the user
    int k;
    scanf("%d", &k);

    // Find the Kth smallest element
    int result = kthSmallest(root, k);

    // Print the result
    printf("%d\n", result);

    return 0;
}