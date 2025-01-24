#include<iostream>
#include<queue>
using namespace std;

// Tree class to operate on trees - Make for binary trees only!!
class Tree {
private:
    // node class for individual elements of the tree
    class node {
    public:
        // defining the property of node
        int val;
        node* left;
        node* right;

        // constructor for node 
        node(int a) {
            this->val = a;
            this->left = nullptr;
            this->right = nullptr;
        }
    };

    // initiating the root of the tree
    // declaring in private class to avoid direct interaction
    node* root = nullptr;

public:
    // Print tree function - LEVEL ORDER TRAVERSAL
    void print_tree() {
        if (root == nullptr) return;  // Edge case: empty tree

        queue<node*> q;
        q.push(root);
        bool isFirstLevel = true;
        bool hasNextLevel = false;

        while (!q.empty()) {
            int level_size = q.size();
            for (int i = 0; i < level_size; ++i) {
                node* front_node = q.front();
                q.pop();

                cout << front_node->val << " ";

                if (front_node->left) {
                    q.push(front_node->left);
                    hasNextLevel = true;
                }
                if (front_node->right) {
                    q.push(front_node->right);
                    hasNextLevel = true;
                }
            }
            cout << endl;  // Line break after each level

            if (!isFirstLevel && !hasNextLevel) {
                // Print -1 for leaf nodes
                for (int i = 0; i < level_size * 2; ++i) {
                    cout << "-1 ";
                }
                cout << endl;
            }

            isFirstLevel = false;
            hasNextLevel = false;
        }
    }

    // function to build tree
    node* make_tree() {
        // declaring variables
        int element = 0;
        queue<node*> q;

        // if the tree doesn't exist - make a node and assign it to root
        if (root == nullptr) {
            cout << "Enter the first element::";
            cin >> element;
            node* new_node = new node(element);
            root = new_node;
            // pushing root to queue
            q.push(new_node);
        }

        // now asking elements of each node and pushing them into queue while queue not empty
        while (!q.empty()) {
            // asking for left child of front node
            cout << "Enter the left of " << q.front()->val << ": ";
            cin >> element;
            // -1 depicts null node - so handle it carefully
            // if-else to avoid insertion of null node in queue
            if (element != -1) {
                node* left = new node(element);
                q.front()->left = left;
                q.push(left);
            } else {
                q.front()->left = nullptr;
            }

            // asking for right child of front node and repeating same process
            cout << "Enter the right of " << q.front()->val << ": ";
            cin >> element;
            if (element != -1) {
                node* right = new node(element);
                q.front()->right = right;
                q.push(right);
            } else {
                q.front()->right = nullptr;
            }

            // removing the front of queue
            q.pop();
        }
        // returning the root, although not needed
        return root;
    }

    // function to swap nodes of a given node
    void swap_nodes(node* root) {
        // storing the left node to preserve it and then swapping
        node* temp = root->left;
        root->left = root->right;
        root->right = temp;
    }

    // function for Inverting the tree
    void invert_tree() {
        // declaring the variables
        node* temp = root;
        queue<node*> q;
        q.push(temp);
        while (!q.empty()) {
            node* front_node = q.front();
            q.pop();

            // if the left child is not null push to queue
            if (front_node->left != nullptr)
                q.push(front_node->left);
            // if the right child is not null push to queue
            if (front_node->right != nullptr)
                q.push(front_node->right);

            // swap the nodes 
            swap_nodes(front_node);
        }
    }
};

int main() {
    // declaring tree class
    Tree my_tree;
    // making the tree
    my_tree.make_tree();
    // printing original tree
    cout << "Original tree:" << endl;
    my_tree.print_tree();
    // inverting the tree
    my_tree.invert_tree();
    // printing inverted tree
    cout << "Inverted tree:" << endl;
    my_tree.print_tree();
}