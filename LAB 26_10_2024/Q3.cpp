#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int value) {
    // Implement here
    TreeNode* node= new TreeNode(data);
    return node;
}

struct TreeNode* buildTreeFromArray(int arr[], int index, int size) {
   // implement
   if(index>size)return nullptr;
    TreeNode*node = createNode(arr[index]);
    node->left=buildTreeFromArray( arr,  2*index+1,  size);
    node->right=buildTreeFromArray( arr,  2*index+2,  size);
    return node;
}

struct TreeNode* getNode(struct TreeNode* root, int value) {
    // implement
    if(root->value==value)return root;
    TreeNode* a=getNode(root->left,value);
    TreeNode* b=getNode(root->right,value);
    if(a)return a;
    if(b)return b;
    return nullptr;
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* n1, struct TreeNode* n2) {
    if (root == nullptr) return nullptr;

    if (root == n1 || root == n2) return root;

    TreeNode* l = lowestCommonAncestor(root->left, n1, n2);
    TreeNode* r = lowestCommonAncestor(root->right, n1, n2);

    if (l && r) return root;

    return (l != nullptr) ? l : r;
}


int main() {
    int size;
    // Enter the size of the array representing the binary tree:
    scanf("%d", &size);

    int arr[size];
    // Enter the elements in level order fashion (enter -1 for NULL nodes):
    for (int i = 0; i < size; ++i) {
        scanf("%d", &arr[i]);
    }

    struct TreeNode* root = buildTreeFromArray(arr, 0, size);
    
    
    // Take User given values of the nodes for which to find the Lowest Common Ancestor: 

    int node1, node2;
   
    scanf("%d %d", &node1, &node2);

    struct TreeNode* n1 = getNode(root, node1);
    struct TreeNode* n2 = getNode(root, node2);

    if (n1 != NULL && n2 != NULL) {
        struct TreeNode* result = lowestCommonAncestor(root, n1, n2);
        printf("%d\n", result->value);
    } else {
        //printf("Invalid node values entered.\n");
    }

    return 0;
}