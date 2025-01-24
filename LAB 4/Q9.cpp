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

    void make_BT_from_array(int *arr, int size) {
        this->root = BT_from_level_order_array(arr, 0, size);
    }

    Node* BT_from_level_order_array(int *arr, int index, int size) {
        if (index < size && arr[index] != -1) {
            Node* newnode = new Node(arr[index]);
            newnode->left = BT_from_level_order_array(arr, 2 * index + 1, size);
            newnode->right = BT_from_level_order_array(arr, 2 * index + 2, size);
            return newnode;
        }
        return nullptr;
    }

    void getans(Node* node, int sign, int sum, int *targets, int *count,int k ) {
        if (node == nullptr) return;

        int temp=sum;
        temp += sign*node->data; 
        
        for (int i = 0; i < k; i++) {
            if(targets[i]==sum){
                count[i]++;
            }
        }

        getans(node->left, -1*sign, temp, targets, count,k);
        getans(node->right, -1*sign, temp, targets, count,k);
    }

    void alternating_path_sum(int *targets, int k) {
        if (k == 0) return; 

        int *count = new int[k];

        for (int i = 0; i < k; i++) {
            count[i]=0;
        }

        getans(root, +1, root->data, targets, count,k);
        cout<<endl;
        for (int i = 0; i < k; i++) {
            cout << count[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    BinaryTree tree;
    int n, data, k;

    cin >> n >> k;
    int *arr = new int[n];
    int *targets = new int[k];

    for (int i = 0; i < n; i++) {
        cin >> data;
        arr[i] = data;
    }

    for (int i = 0; i < k; i++) {
        cin >> data;
        targets[i] = data;
    }

    tree.make_BT_from_array(arr, n);
    tree.alternating_path_sum(targets, k);

    delete[] arr;    
    delete[] targets; 

    return 0;
}
