#include <iostream>
#include <unordered_map>
using namespace std;

class BinaryTree {
public:
    class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val = 0, Node* left = nullptr, Node* right = nullptr) {
            data = val;
            this->left = left;
            this->right = right;
        }
    };

    Node* root = nullptr;

    // Function to build the binary tree from a level-order array
    void make_BT_from_array(int* arr, int size) {
        this->root = BT_from_level_order_array(arr, 0, size);
    }

    Node* BT_from_level_order_array(int* arr, int index, int size) {
        if (index < size && arr[index] != -1) {
            Node* newnode = new Node(arr[index]);
            newnode->left = BT_from_level_order_array(arr, 2 * index + 1, size);
            newnode->right = BT_from_level_order_array(arr, 2 * index + 2, size);
            return newnode;
        }
        return nullptr;
    }

    // Recursive function to calculate alternating path sums
    void getans(Node* node, int check, int sum, unordered_map<int, bool>& target_nodes, unordered_map<int, int>& count) {
        if (node == nullptr) return;
        int new_sum=sum+ check*node->data;
        // Check if the current sum matches any target value
        if (target_nodes[new_sum]==true) {
            count[new_sum]++;
        }

        

        getans(node->left,-1*check, new_sum, target_nodes, count);
        getans(node->right, -1*check, new_sum, target_nodes, count);
    }

    // Function to calculate the alternating path sums based on target values
    void alternating_path_sum(int* targets, int k) {
        if (k == 0 || root == nullptr) return;

        unordered_map<int, bool> target_nodes;
        unordered_map<int, int> count;

        // Initialize target nodes map and count map
        for (int i = 0; i < k; i++) {
            target_nodes[targets[i]] = true;
            count[targets[i]] = 0;
        }

        // Start calculating from the root node
        getans(root, true, 0, target_nodes, count);

        cout << endl;
        for (int i = 0; i < k; i++) {
            cout << count[targets[i]] << " ";
        }
        cout << endl;
    }
};

int main() {
    BinaryTree tree;
    int n, k;

    cin >> n >> k;
    int* arr = new int[n];
    int* targets = new int[k];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < k; i++) {
        cin >> targets[i];
    }

    // Build the binary tree from the input array
    tree.make_BT_from_array(arr, n);
    
    // Calculate and output the alternating path sums for the given target values
    tree.alternating_path_sum(targets, k);

    delete[] arr;    
    delete[] targets; 

    return 0;
}
