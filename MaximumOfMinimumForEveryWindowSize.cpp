#include <stack>
vector<int> maxMinWindow(vector<int> a, int n) {
    vector<int> answer(n, INT_MIN);
    vector<int> nextSmaller(n, n);
    vector<int> prevSmaller(n, -1);
    stack<int> st;
    // prevSmaller
    for(int i = 0; i < n; i++) {
        while(!st.empty() && a[st.top()] >= a[i])
            st.pop();
        if(!st.empty()) prevSmaller[i] = st.top();
        st.push(i);
    }
    while(!st.empty()) st.pop();
    // nextSmaller
    for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() && a[st.top()] >= a[i])
            st.pop();
        if(!st.empty()) nextSmaller[i] = st.top();
        st.push(i);
    }
    
    for(int i = 0; i < n; i++) {
        int len = nextSmaller[i] - prevSmaller[i] - 1;
        answer[len - 1] = max(answer[len - 1], a[i]);
    }
    for(int i = n - 2; i >= 0; i--)
        answer[i] = max(answer[i], answer[i+1]);
    return answer;
}