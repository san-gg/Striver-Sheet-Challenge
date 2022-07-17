#include <bits/stdc++.h>
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    unordered_map<int, int> mp;
    for(int x : arr) mp[x]++;
    priority_queue<pair<int,int>> pq;
    for(auto &p : mp)
        pq.push({p.second, p.first});
    vector<int> answer;
    for(int i = 0; i < k; i++) {
        auto &p = pq.top();
        answer.push_back(p.second);
        pq.pop();
    }
    sort(answer.begin(), answer.end());
    return answer;
}