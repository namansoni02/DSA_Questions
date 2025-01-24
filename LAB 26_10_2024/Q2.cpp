#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
#define MAX_NODES 100

// Structure to represent a node in the tree
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
    
    TreeNode(int n){
        data=n;
        left=nullptr;
        right=nullptr;
        
    }
};

// Function to create a new tree node
struct TreeNode* createNode(int data) {
    // TODO: Implement the function
    TreeNode* node= new TreeNode(data);
    return node;
}

// Function to find the maximum depth of the tree
int maxDepth(struct TreeNode* root) {
    // TODO: Implement the function
    if(root==nullptr)return 0;
    int max=0;
    int a1=maxDepth(root->left);
    int a2=maxDepth(root->right);
    max+=(a1>a2)?a1:a2;
    return max+1;
}

// Function to build the tree from array representation
struct TreeNode* buildTree(int arr[], int index, int size) {
    // TODO: Implement the function
    if(index>size)return nullptr;
    TreeNode*node = createNode(arr[index]);
    node->left=buildTree( arr,  2*index+1,  size);
    node->right=buildTree( arr,  2*index+2,  size);
    return node;
}

int main() {
    int n;
    // TODO: Input the number of nodes in the tree
    cin>>n;

    if (n <= 0 || n > MAX_NODES) {
        // TODO: Handle invalid input
        cout<<"0";
        return 1;
    }
    int arr[n];
    int treeArray[MAX_NODES]; // input should be in array format (root left_child right_child):
    // TODO: Input the tree nodes in array format
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    

    struct TreeNode* root = buildTree(treeArray, 0, n);

    // TODO: Calculate and print the maximum depth of the tree
    
     printf("%d\n", maxDepth(root));


  

    return 0;
}