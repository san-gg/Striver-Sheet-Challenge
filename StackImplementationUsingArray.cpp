// Stack class.
class Stack {
    vector<int> arr;
    int indx;
public:
    
    Stack(int capacity) : indx(-1), arr(capacity, 0) {
        // Write your code here.
    }

    void push(int num) {
        arr[++indx] = num;
    }

    int pop() {
        // Write your code here.
        if(indx == -1) return -1;
        int val = arr[indx--];
        return val;
    }
    
    int top() {
        if(indx == -1) return -1;
        return arr[indx];
    }
    
    int isEmpty() {
        if(indx == -1) return 1;
        return 0;
    }
    
    int isFull() {
        if(indx+1 == arr.size()) return 1;
        return 0;
    }
    
};