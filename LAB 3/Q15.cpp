#include <iostream>
using namespace std;

class LRUCache {
public:
    class Node {
    public:
        int key;
        int value;
        Node* next;
        Node* prev;

        Node() : key(0), value(0), next(nullptr), prev(nullptr) {};
        Node(int x, int y) : key(x), value(y), next(nullptr), prev(nullptr) {};
    };

    Node* head;
    Node* tail;
    int maxsize;
    int size;

    LRUCache(int x) : head(nullptr), tail(nullptr), maxsize(x), size(0) {};

    void enqueue(int x, int y) {
        Node* newNode = new Node(x, y);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    bool isEmpty() {
        return (head == nullptr);
    }

    int dequeue() {
        if (isEmpty()) {std::cout << "Stack underflow" << std::endl ; exit(EXIT_FAILURE); }
        Node* popped = tail;
        int val = popped->key;
        
        if (tail == head) {
            head = nullptr;
            tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete popped;
        size--;
        return val;
    }

    int get(int x) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->key == x) {
                pop_and_insert(x, temp->value);
                return temp->value;
            }
            temp = temp->next;
        }
        return -1;
    }

    bool pop_and_insert(int x, int y) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->key == x) {
                temp->value = y;

                if (temp != head) {
                    if (temp->prev) temp->prev->next = temp->next;
                    if (temp->next) temp->next->prev = temp->prev;

                    if (temp == tail) {
                        tail = temp->prev;
                    }

                    temp->next = head;
                    temp->prev = nullptr;
                    head->prev = temp;
                    head = temp;
                }
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void put(int x, int y) {
        if (pop_and_insert(x, y)) {
            return;
        }

        if (size == maxsize) {
            dequeue();
        }

        enqueue(x, y);
    }
};

int main() {
    int n, numOps, op, num1, num2;
    std::cin >> n >> numOps;
    LRUCache cache(n);

    for (; numOps; numOps--) {
        std::cin >> op;
        if (op == 1) {
            std::cin >> num1;
            std::cout << cache.get(num1) << std::endl;
        } else {
            std::cin >> num1 >> num2;
            cache.put(num1, num2);
        }
    }
    return 0;
}
