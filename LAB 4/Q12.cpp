#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
public:
    Node* root = nullptr;

    Node* insert(Node* node, int data) {
        if (node == nullptr) {
            return new Node(data);
        }
        if (data > node->data) {
            node->right = insert(node->right, data);
        } else {
            node->left = insert(node->left, data);
        }
        return node;
    }

    void maketree(int n) {
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            root = insert(root, x);
        }
    }

    void traverse(Node* root, vector<int>& ans) {
        if (root == nullptr) return;
        traverse(root->left, ans);
        ans.push_back(root->data);
        traverse(root->right, ans);
    }

    vector<int> inOrderTraversal() {
        vector<int> ans;
        traverse(root, ans);
        return ans;
    }
};

int main() {
    int n;
    cin >> n;

    BST bst;
    bst.maketree(n);
    vector<int> inOrder = bst.inOrderTraversal();
    for (int val : inOrder) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
