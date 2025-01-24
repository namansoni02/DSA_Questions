#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class BinaryTree{
    public:
    class Node {
        public:
        int data;
        Node* left;
        Node* right;
        
        Node(): data(0), left(nullptr), right(nullptr) {}
        
        Node(int val): data(val), left(nullptr), right(nullptr) {}
    };
    
    Node* root = nullptr;
    
    void make_BT_from_array(int *arr, int size)
    {
        this->root = BT_from_level_order_array(arr, 0, size);
    }
    
    Node* BT_from_level_order_array(int *arr, int index, int size){

        if (index < size && arr[index] != -1) {
            Node* newnode = new Node(arr[index]);
            newnode->left = BT_from_level_order_array(arr, 2 * index + 1, size);
            newnode->right = BT_from_level_order_array(arr, 2 * index + 2, size);
            return newnode;
        }
        return nullptr;
    }
    void alternatingLevelOrderTraversal() {
    if (root == nullptr) return; 
    queue<Node*> q;
    stack<Node*> s;
    bool check = true;  

    q.push(root);
    q.push(nullptr); 

    while (!q.empty()) {
        if (q.front() == nullptr) {  
            cout << "| ";  
            q.pop();
            if (!q.empty()) {
                check = !check;  
                q.push(nullptr);  
            }
        } 
        else if (check) {  
            Node* temp = q.front();
            q.pop();
                cout << temp->data << " ";
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right); 
        } 
        else { 
            while (q.front() != nullptr) {  
                Node* temp = q.front();
                q.pop();
                    if (temp->left) q.push(temp->left); 
                    if (temp->right) q.push(temp->right);  
                    s.push(temp); 
            }
            while (!s.empty()) {
                cout << s.top()->data << " ";
                s.pop();
            }
            // q.pop();  // Remove the `nullptr` delimiter for this level
            // cout<<"| ";
            //q.push(nullptr);
        }
    }
}

    
};

int main() {
    BinaryTree tree;
    int n, data;
    std::cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++) {
        std::cin >> data;
        arr[i] = data;
    }
    
    tree.make_BT_from_array(arr,n);
    tree.alternatingLevelOrderTraversal();
    return 0;
}