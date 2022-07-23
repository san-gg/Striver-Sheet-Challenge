#include <queue>
class Queue {
    deque<int> ds;
public:
    Queue() {
        // Implement the Constructor
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        return ds.empty();
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        ds.push_back(data);
    }

    int dequeue() {
        // Implement the dequeue() function
        if(isEmpty()) return -1;
        int val = ds.front();
        ds.pop_front();
        return val;
    }

    int front() {
        // Implement the front() function
        if(isEmpty()) return -1;
        return ds.front();
    }
};