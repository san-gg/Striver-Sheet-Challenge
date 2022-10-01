#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<int> nodes(v, 0);
    unordered_map<int, vector<int>> adj;
    queue<int> q;
    vector<int> ans;
    for(auto &p : edges) {
        nodes[p[1]] += 1;
        adj[p[0]].push_back(p[1]);
    }
    for(int i = 0; i < v; i++) {
        if(nodes[i] == 0) q.push(i);
    }
    while(!q.empty()) {
        int nd = q.front(); q.pop();
        ans.push_back(nd);
        for(auto x : adj[nd]) {
            if(--nodes[x] == 0) q.push(x);
        }
    }
    return ans;
}