#include <queue>
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < b.size(); j++) {
            pq.push(a[i] + b[j]);
            if(pq.size() > k)
                pq.pop();
        }
    }
    vector<int> answer(k, 0);
    int x = k-1;
    while(!pq.empty()) {
        answer[x--] = pq.top();
        pq.pop();
    }
    return answer;
}