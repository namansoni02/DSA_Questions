#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}

   
};
 
// Function to insert nodes in level order using a queue
TreeNode* insertLevelOrder(vector<int>& arr) {
    if (arr.empty() || arr[0] == -1) return nullptr;

    // Create the root of the tree
    TreeNode* root = new TreeNode(arr[0]);

    // Create a queue for level-order insertion
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < arr.size()) {
        TreeNode* currentNode = q.front();
        q.pop();

        // Insert left child
        if (i < arr.size() && arr[i] != -1) {
            currentNode->left = new TreeNode(arr[i]);
            q.push(currentNode->left);
        }
        i++;

        // Insert right child
        if (i < arr.size() && arr[i] != -1) {
            currentNode->right = new TreeNode(arr[i]);
            q.push(currentNode->right);
        }
        i++;
    }
    return root;
}

// Function to invert the binary tree iteratively using a stack
TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) return nullptr;

    stack<TreeNode*> nodeStack;
    nodeStack.push(root);

    while (!nodeStack.empty()) {
        TreeNode* currentNode = nodeStack.top();
        nodeStack.pop();

        // Swap the left and right children
        TreeNode* temp = currentNode->left;
        currentNode->left = currentNode->right;
        currentNode->right = temp;

        if (currentNode->left) nodeStack.push(currentNode->left);
        if (currentNode->right) nodeStack.push(currentNode->right);
    }

    return root;
}

// Function to print the tree in level-order using a queue
void printLevelOrder(TreeNode* root) {
    if (root == nullptr) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* currentNode = q.front();
        q.pop();
        cout << currentNode->value << " ";

        if (currentNode->left) q.push(currentNode->left);
        if (currentNode->right) q.push(currentNode->right);
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Build the tree in level-order
    TreeNode* root = insertLevelOrder(arr);

    // Print the original tree in level-order
   
    printLevelOrder(root);

    // Invert the tree and print the result in level-order
    root = invertTree(root);
    
    printLevelOrder(root);

    // Clean up memory
    delete root;

    return 0;
}