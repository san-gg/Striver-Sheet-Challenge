#include <queue>
vector<int> minHeap(int n, vector<vector<int>>& q) {
    // At this moment I was lazy to implement heap... lol
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> ans;
    for(auto &v : q) {
        if(v[0] == 0) pq.push(v[1]);
        else if(v[0] == 1) {
            ans.push_back(pq.top());
            pq.pop();
        }
    }
    return ans;
}