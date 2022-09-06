/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/
// Unoptimized code though!!
#include <stack>
bool addOrRemove(int x, vector<int> &list) {
    for(int i = 0; i < list.size(); i++) {
        if(!knows(list[i], x) || knows(x, list[i])) {
            list.push_back(x);
            return true; // add
        }
    }
    return false; // not added
}

int findCelebrity(int n) {
    // Write your code here.
    vector<int> list;
    stack<int> st;
    for(int i = 0; i < n; i++) {
        if(st.empty() && list.size() > 0) {
            if(!addOrRemove(i, list)) {
                st.push(i);
            }
        }
        else if(!st.empty()) {
            bool a = knows(st.top(), i);
            bool b = knows(i, st.top());
            if((a == false && b == false) || (a == true && b == true)) {
                list.push_back(st.top());
                list.push_back(i);
                st.pop();
            } else if(a == true) {
                list.push_back(st.top());
                st.pop();
                st.push(i);
                if(addOrRemove(i, list)) {
                    st.pop();
                    list.push_back(i);
                }
            } else if(b == true) {
                list.push_back(i);
            }
        } else {
            st.push(i);
        }
    }
    if(st.empty()) return -1;
    return st.top();
}