#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int key;
    struct Node *left, *right;
    int height;

    Node(int key){
        this->key = key;
        left = nullptr;
        right = nullptr;
        height = 1; 
    }
};

// Utility function to get maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to get height of the tree
int height(Node *N) {
    if (N == nullptr) return 0; // Height of a null node is 0
    return N->height;
}

// Helper function to create a new node with the given key
Node* newNode(int key) {
    Node* temp = new Node(key);
    return temp;
}

// Function to right rotate subtree rooted with y
Node* rightRotate(Node *y) {
    Node* new_node = y->left;
    y->left = new_node->right;
    new_node->right = y;

    y->height = 1 + max(height(y->left), height(y->right));
    new_node->height = 1 + max(height(new_node->left), height(new_node->right));
    
    return new_node;
}

// Function to left rotate subtree rooted with x
Node* leftRotate(Node *x) {
    Node* new_node = x->right;
    x->right = new_node->left;
    new_node->left = x;

    x->height = 1 + max(height(x->left), height(x->right));
    new_node->height = 1 + max(height(new_node->left), height(new_node->right));

    return new_node;
}

// Get Balance factor of node N
int getBalance(Node *N) {
    if (N == nullptr) return 0;
    return height(N->left) - height(N->right);
}

// Recursive function to insert a key into the subtree rooted with node
// and returns the new root of the subtree.
Node* insert(Node* node, int key) {
    if (node == NULL) {
        Node* new_node = new Node(key);
        return new_node;
    }
    if (key < node->key) 
        node->left = insert(node->left, key);
    else if (key > node->key) 
        node->right = insert(node->right, key);
    else
        return node; 
    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Utility function to find the node with the minimum key in the tree
Node* findMin(Node* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

// Recursive function to delete a node with given key from subtree with given root
// It returns root of the modified subtree.
Node* deleteNode(Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL || root->right == NULL) {
            Node *temp = root->left ? root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp; 

            delete temp;
        } else {
            Node* temp = findMin(root->right);

            root->key = temp->key;

            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == NULL) return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// A utility function to do preorder traversal of the tree
void preOrder(Node *root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    Node *root = NULL;
    int n, key;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> key;
        root = insert(root, key);
    }

    cin >> key;
    root = deleteNode(root, key);

    preOrder(root);

    return 0;
}
