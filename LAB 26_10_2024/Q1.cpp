#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

// Node structure for the binary tree.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int n) : val(n), left(nullptr), right(nullptr) {}
};

class BT {
private:
    TreeNode* root;

    // Helper function to build the tree from inorder and preorder traversals.
    TreeNode* buildTree(vector<int>& inorder, vector<int>& preorder,
                        unordered_map<int, int>& inorderMap,
                        int inStart, int inEnd, int& preIndex) {
        if (inStart > inEnd) return nullptr;

        int currentVal = preorder[preIndex++];
        TreeNode* node = new TreeNode(currentVal);

        if (inStart == inEnd) return node;

        int inIndex = inorderMap[currentVal];

        node->left = buildTree(inorder, preorder, inorderMap, inStart, inIndex - 1, preIndex);
        node->right = buildTree(inorder, preorder, inorderMap, inIndex + 1, inEnd, preIndex);

        return node;
    }

public:
    TreeNode *head = nullptr;

    BT() : root(nullptr) {}

    TreeNode* make_BT_from_pre_in(int n, vector<int>& preorder, vector<int>& inorder, int& k) {
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < n; i++) {
            inorderMap[inorder[i]] = i;
        }
        int preIndex = 0;

        head = buildTree(inorder, preorder, inorderMap, 0, n - 1, preIndex);
        return head;
    }

    void levelOrderTraversal(TreeNode* root) {
        if (!root) {
            cout << "-1 ";
            return;
        }

        queue<TreeNode*> q;
        q.push(root);
        bool hasMoreNodes = true; // Flag to track if there are more nodes to process

        while (hasMoreNodes) {
            int levelSize = q.size();
            hasMoreNodes = false; // Reset for the current level
            vector<int> currentLevel;

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* curr = q.front();
                q.pop();

                currentLevel.push_back(curr->val); // Add current node value

                if (curr->left) {
                    q.push(curr->left);
                    hasMoreNodes = true; // There are more nodes in the next level
                } else {
                    currentLevel.push_back(-1); // Add -1 for the left null child
                }

                if (curr->right) {
                    q.push(curr->right);
                    hasMoreNodes = true; // There are more nodes in the next level
                } else {
                    currentLevel.push_back(-1); // Add -1 for the right null child
                }
            }

            // Print the current level values, excluding trailing -1s
            for (int j = 0; j < currentLevel.size(); j++) {
                // Only print -1s if they are not trailing the last level
                if (currentLevel[j] == -1 && !hasMoreNodes) {
                    // Skip printing trailing -1s in the last level
                    break;
                }
                cout << currentLevel[j] << " ";
            }
        }
    }
};

int main() {
    vector<int> levelOrderInput = {3, 9, 20, -1, -1, 15, 7};

    BT tree;
    tree.make_BT_from_pre_in(levelOrderInput.size(), levelOrderInput, levelOrderInput, 0);
    tree.levelOrderTraversal(tree.head);  // This will print the tree in level order

    return 0;
}
