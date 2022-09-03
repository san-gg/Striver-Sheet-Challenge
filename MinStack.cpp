// Implement class for minStack.
#include <stack>
class minStack
{
	// Write your code here.
	
	public:
		stack<int> stck;
        stack<int> minE;
		// Constructor
		minStack() 
		{ 
			// Write your code here.
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			// Write your code here.
            stck.push(num);
            if(minE.size() == 0) minE.push(num);
            else if(minE.top() <= num) minE.push(minE.top());
            else if(minE.top() > num) minE.push(num);
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
			// Write your code here.
            if(stck.empty()) return -1;
            int x = stck.top();
            stck.pop();
            minE.pop();
            return x;
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			// Write your code here.
            if(stck.empty()) return -1;
            return stck.top();
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			// Write your code here.
            if(minE.empty()) return -1;
            return minE.top();
		}
};