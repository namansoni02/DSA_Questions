    // Write a C++ program to perform basic operations on a queue. The program should include functions for enqueueing, dequeueing, checking the front element, determining if the queue is full, and checking if the queue is empty. The queue should be capable of holding up to 100 integers.

    // The program must take an input of n number of integers and enqueue them into the queue. After the enqueueing process, the program should execute the following operations in the specified order and print their outputs:

    // front(): Print the element at the front of the queue.
    // dequeue(): Remove and print the element at the front of the queue.
    // printWholeQueue(): This function should empty the queue and print all the elements in the order they were dequeued.
    // isFull(): Print 1 if the queue is full, otherwise 0.
    // isEmpty(): Print 1 if the queue is empty, otherwise 0.
    // Input Format:

    // The first line of input should be the number of elements, N.
    // The second line should contain N integers, separated by spaces.
    // Output Format:

    // Output the result of front() on a new line.
    // Output the result of dequeue() on a new line.
    // Output the elements in the queue, emptied by printWholeQueue(), on a new line.
    // Output 1 or 0 for isFull() on a new line.
    // Output 1 or 0 for isEmpty() on a new line.
    // Example:

    // Input:
    // 5
    // 15 123 62 10 44
    // Output:
    // 15
    // 15
    // 123 62 10 44 
    // 0 
    // 1 
    #include <iostream>
#define MAX 100

using namespace std;

// Queue structure
class Queue {
private:
    int items[MAX];
    int front, rear;

public:
    // Constructor to initialize the queue
    Queue() {
        front = -1;
        rear = -1;
    }

    // Check if the queue is full
    bool isFull() {
        return rear == MAX - 1;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == -1 || front > rear;
    }

    // Enqueue an element
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full, cannot enqueue" << endl;
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        rear++;
        items[rear] = value;
    }

    // Dequeue an element
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty, cannot dequeue" << endl;
            return -1;
        }
        int value = items[front];
        front++;
        // Reset the queue if all elements are dequeued
        if (front > rear) {
            front = rear = -1;
        }
        return value;
    }

    // Get the front element
    int getFront() {
        if (!isEmpty()) {
            return items[front];
        }
        return -1;
    }

    // Print and empty the entire queue
    void printWholeQueue() {
        while (!isEmpty()) {
            cout << getFront() << " ";
            dequeue();
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    int n;
    cin >> n;
    int value;

    for (int i = 0; i < n; i++) {
        cin >> value;
        q.enqueue(value);
    }

    // Print the front element using getFront()
    cout << q.getFront() << endl;

    // Dequeue and print an element using dequeue()
    cout << q.dequeue() << endl;

    // Print and empty the whole queue using printWholeQueue()
    q.printWholeQueue();

    // Print if the queue is full using isFull()
    cout << (q.isFull() ? "Queue is full" : "Queue is not full") << endl;

    // Print if the queue is empty using isEmpty()
    cout << (q.isEmpty() ? "Queue is empty" : "Queue is not empty") << endl;

    return 0;
}
