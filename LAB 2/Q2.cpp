#include <iostream>
#include <vector>
using namespace std;

class LinkedList {
public:
    class Node {
    public:
        char data;
        Node *next;
        Node(char value) {
            this->data = value;
            this->next = nullptr;
        }
    };

    int size;
    Node *root;

    LinkedList() {
        this->size = 0;
        this->root = nullptr;
    }

    void enqueue(char value) {
        Node* newNode = new Node(value);
        if (root == nullptr) {
            root = newNode;
        } else {
            Node* curr = root;
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = newNode;
        }
        this->size++;
    }

    void traverse() {
        Node *ptr = root;
        while (ptr != nullptr) {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }

    bool check_0(int a, int b) {
        if (a == 1) return false;
        return (a - b >= 1);
    }

    void solution() {
        //cout<<root->data;
        vector<char> ans;
        int x_count = 0, o_count = 0;
        Node* temp = root;

        while (temp != nullptr) {
            if (temp->data == 'x') {
                x_count++;
            } else {
                o_count++;
            }
            temp = temp->next;
        }

        temp = root;
        int x = x_count, y = o_count;

        for (int i = 0; i < size / 2 + 1; i++) {
            if (x_count - o_count > 1) o_count++;
            else x_count++;
        }

        x_count -= x;
        o_count -= y;
        //cout<<x_count<<" "<<o_count;
        int a = 1, b = 1;
        temp = root;

        while (temp->next != nullptr) {
            if (temp->data == 'x') a++;
            else b++;
            if (check_0(a, b + 1)) {
                ans.push_back('o');
                b++;
                o_count--;
            } else {
                ans.push_back('x');
                a++;
                x_count--;
            }
            temp = temp->next;
        }
       
        a = 1;
        b = 1;
        temp = root;
        int idx = 0;
        //for(auto i:ans)cout<<i<<" ";
        while (temp != nullptr) {
            if (temp->data == 'x') {
                cout << "x" << a++ << " ";
            } else {
                cout << "o" << b++ << " ";
            }

            if (idx < ans.size()) {
                if (ans[idx] == 'x') {
                    cout << "x" << a++ << " ";
                } else {
                    cout << "o" << b++ << " ";
                }
                idx++;
            }

            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList L;
    int size;
    cin >> size;

    for (int i = 0; i < size; i++) {
        char c;
        cin>>c;
        L.enqueue(c);
    }
    //L.traverse();
    L.solution();

    return 0;
}
