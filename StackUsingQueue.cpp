#include <queue>
class Stack {
    // Define the data members.
    queue<int> q1;
   public:
    Stack() {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function.
        return q1.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        return q1.empty();
    }

    void push(int element) {
        // Implement the push() function.
        vector<int> tmp;
        tmp.push_back(element);
        while(!q1.empty()) {
            tmp.push_back(q1.front());
            q1.pop();
        }
        for(int i = 0; i < tmp.size(); ++i) {
            q1.push(tmp[i]);
        }
    }

    int pop() {
        // Implement the pop() function.
        if(q1.empty()) return -1;
        int x = q1.front();
        q1.pop();
        return x;
    }

    int top() {
        // Implement the top() function.
        if(q1.empty()) return -1;
        return q1.front();
    }
};