/*A double-ended queue(deque) is a linear list in which 
additions and deletions may be made at either end. Obtain a 
data representation mapping a deque into a one-dimensional 
array. Write C++ program to simulate deque with functions to 
add and delete elements from either end of the deque.*/

#include <iostream>
using namespace std;

class Deque {
private:
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;

public:
    Deque(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];
        front = -1;
        rear = -1;
        size = 0;
    }

    ~Deque() {
        delete[] arr;
    }

    // Check if the deque is full
    bool isFull() {
        return size == capacity;
    }

    // Check if the deque is empty
    bool isEmpty() {
        return size == 0;
    }

    // Insert element at the front
    void insertFront(int element) {
        if (isFull()) {
            cout << "Deque is full. Cannot insert at front." << endl;
            return;
        }
        if (front == -1) {
            front = rear = 0;
        } else if (front == 0) {
            front = capacity - 1;
        } else {
            front--;
        }
        arr[front] = element;
        size++;
    }

    // Insert element at the rear
    void insertRear(int element) {
        if (isFull()) {
            cout << "Deque is full. Cannot insert at rear." << endl;
            return;
        }
        if (rear == -1) {
            front = rear = 0;
        } else if (rear == capacity - 1) {
            rear = 0;
        } else {
            rear++;
        }
        arr[rear] = element;
        size++;
    }

    // Delete element from the front
    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot delete from front." << endl;
            return;
        }
        if (front == rear) {
            front = rear = -1;
        } else if (front == capacity - 1) {
            front = 0;
        } else {
            front++;
        }
        size--;
    }

    // Delete element from the rear
    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot delete from rear." << endl;
            return;
        }
        if (front == rear) {
            front = rear = -1;
        } else if (rear == 0) {
            rear = capacity - 1;
        } else {
            rear--;
        }
        size--;
    }

    // Get the front element
    int getFront() {
        if (isEmpty()) {
            cout << "Deque is empty. No front element." << endl;
            return -1;
        }
        return arr[front];
    }

    // Get the rear element
    int getRear() {
        if (isEmpty()) {
            cout << "Deque is empty. No rear element." << endl;
            return -1;
        }
        return arr[rear];
    }
};

int main() {
    Deque dq(5);

    dq.insertRear(5);
    dq.insertRear(10);
    dq.insertFront(15);
    dq.insertFront(20);
    dq.insertRear(25);

    cout << "Front element: " << dq.getFront() << endl;
    cout << "Rear element: " << dq.getRear() << endl;

    dq.deleteFront();
    cout << "Front element after deletion: " << dq.getFront() << endl;

    dq.deleteRear();
    cout << "Rear element after deletion: " << dq.getRear() << endl;

    return 0;
}
