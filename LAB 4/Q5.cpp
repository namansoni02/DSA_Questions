#include <iostream>
#include <algorithm>

using namespace std;

// Class for AVL Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new AVL tree node
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Function to get the height of a node
int getHeight(Node* node) {
    if (node == nullptr) return 0;
    return max(getHeight(node->left), getHeight(node->right)) + 1;
}

// Function to right rotate subtree rooted with y
Node* rightRotate(Node* y) {
    Node* new_node = y->left;
    y->left = new_node->right;
    new_node->right = y;
    return new_node;
}

// Function to left rotate subtree rooted with x
Node* leftRotate(Node* x) {
    Node* new_node = x->right;
    x->right = new_node->left;
    new_node->left = x;
    return new_node;
}

// Get Balance factor of node N
int getBalance(Node* N) {
    if (N == nullptr) return 0;
    return getHeight(N->left) - getHeight(N->right);
}

// Function to insert a node in AVL tree and balance the tree
Node* insert(Node* node, int data) {
    if (node == nullptr) {
        return new Node(data);
    }

    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    }

    int balance = getBalance(node);

    if (balance > 1 && data < node->left->data) {
        return rightRotate(node);
    }

    if (balance < -1 && data > node->right->data) {
        return leftRotate(node);
    }

    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

bool isValidAVL(Node* root) {
    if(root==nullptr)return true;

    int bal=getBalance(root);

    if(bal<-1 || bal>1)return false;

    return isValidAVL(root->left)&&isValidAVL(root->right);
}

// Function to perform preorder traversal of the AVL tree
void preorderTraversal(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main() {
    int n;
    cin >> n;
    Node* root = nullptr;

    for (int i = 0; i < n; ++i) {
        int data;
        cin >> data;
        root = insert(root, data);
    }

    preorderTraversal(root);
    cout << endl;

    if (isValidAVL(root)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}
