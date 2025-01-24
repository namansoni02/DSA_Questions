#include <iostream>
using namespace std;

class LinkedList {
public:
    class Node {
    public:
        int data;
        Node* next;
        
        Node(int data) {
            this->data = data;
            this->next = nullptr;
        }
    };
    
    int size;
    Node *root;
    
    LinkedList() {
        root = nullptr;
        size = 0;
    }
    
    ~LinkedList() {
        Node* temp = root;
        while (temp != nullptr) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
    
    void push(int value) {
        if (root == nullptr) {
            root = new Node(value);
        } else {
            Node* temp = root;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = new Node(value);
        }
        size++;
    }
    
    void printList() {
        Node* temp = root;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) {
                cout << "->";
            }
            temp = temp->next;
        }
        cout << endl;
    }
    
    int solution() {
        if (size < 3) return 0;
        
        int ans = 0;
        for (int a = 1; a <= size - 2; a++) {
            for (int b = 1; b <= size - a - 1; b++) {
                int c = size - a - b;
                if (check(a, b, c)) {
                    ans++;
                }
            }
        }
        return ans;
    }
    
    bool check(int a, int b, int c) {
        Node* temp = root;
        int sum1 = 0, sum2 = 0, sum3 = 0;
        
        for (int i = 0; i < a && temp != nullptr; i++) {
            sum1 += temp->data;
            temp = temp->next;
        }
        
        for (int i = 0; i < b && temp != nullptr; i++) {
            sum2 += temp->data;
            temp = temp->next;
        }
        
        for (int i = 0; i < c && temp != nullptr; i++) {
            sum3 += temp->data;
            temp = temp->next;
        }
        //cout<<sum1+sum3<<" "<<sum2<<endl;
        return (sum1 + sum3) == sum2;
    }
};

int main() {
    LinkedList L;
    int size;
    
    cin >> size;
    for (int i = 0; i < size; i++) {
        int x;
        cin >> x;
        L.push(x);
    }
    
    //L.printList();
    cout << L.solution() << endl;
    
    return 0;
}