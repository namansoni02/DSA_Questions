#include <iostream>
#include <vector>
using namespace std;

// Class definition for a Node in the BST
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Class definition for the Binary Search Tree
class BST {
private:
    Node* root;

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

    Node* findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    Node* findNode(Node* node, int data) {
        if (node == nullptr || node->data == data) {
            return node;
        }
        if (data > node->data) {
            return findNode(node->right, data);
        }
        return findNode(node->left, data);
    }

public:
    BST() {
        root = nullptr;
    }

    void insert(int data) {
        root = insert(root, data);
    }

    void traverse(Node* root, vector<int>& ans) {
        if (root == nullptr) return;
        traverse(root->left, ans);
        ans.push_back(root->data);
        traverse(root->right, ans);
    }

    int findInOrderSuccessor(int data) {
        Node* target = findNode(root, data);
        if (target == nullptr) return -1;

        if (target->right != nullptr) {
            Node* successor = findMin(target->right);
            return successor->data;
        }

        Node* successor = nullptr;
        Node* ancestor = root;
        while (ancestor != target) {
            if (data < ancestor->data) {
                successor = ancestor;
                ancestor = ancestor->left;
            } else {
                ancestor = ancestor->right;
            }
        }

        return (successor != nullptr) ? successor->data : -1;
    }
};

// Main function to execute the program
int main() {
    int n, target;
    cin >> n;

    BST tree;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        tree.insert(val);
    }

    cin >> target;

    int successor = tree.findInOrderSuccessor(target);
    if (successor != -1) {
        cout << successor << endl;
    } else {
        cout << "-1" << endl;
    }

    return 0;
}
