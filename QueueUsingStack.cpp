#include <stack>
class Queue {
    // Define the data members(if any) here.
    stack<int> s;
    int sz = 0;
    public:
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        // Implement the enqueue() function.
        vector<int> tmp;
        while(!s.empty()) {
            tmp.push_back(s.top());
            s.pop();
        }
        tmp.push_back(val);
        for(int i = tmp.size()-1; i >= 0; --i) s.push(tmp[i]);
    }

    int deQueue() {
        // Implement the dequeue() function.
        if(s.empty()) return -1;
        int a = s.top();
        s.pop();
        return a;
    }

    int peek() {
        // Implement the peek() function here.
        if(s.empty()) return -1;
        return s.top();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here.
        return s.empty();
    }
};