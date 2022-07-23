#include <stack>
vector<int> nextGreater(vector<int> &arr, int n) {
    // Write your code here
    stack<pair<int, int>> s;
    vector<int> answer(n, -1);
    for(int i = 0; i < n; i++) {
        while(!s.empty() && s.top().first < arr[i]) {
            answer[s.top().second] = arr[i];
            s.pop();
        }
        s.push({arr[i], i});
    }
    return answer;
}