#include <queue>
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for(auto &x: kArrays) {
        for(int i : x)
            pq.push(i);
    }
    vector<int> answer;
    while(!pq.empty()) {
        answer.push_back(pq.top());
        pq.pop();
    }
    return answer;
}