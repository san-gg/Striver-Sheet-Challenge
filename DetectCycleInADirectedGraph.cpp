#include <bits/stdc++.h>
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    vector<int> nodes(n+1, 0);
    unordered_map<int, vector<int>> adj;
    queue<int> q;
    for(auto &p : edges) {
        nodes[p.second] += 1;
        adj[p.first].push_back(p.second);
    }
    for(int i = 1; i <= n; i++) {
        if(nodes[i] == 0) q.push(i);
    }
    while(!q.empty()) {
        int nd = q.front(); q.pop();
        for(auto x : adj[nd]) {
            if(--nodes[x] == 0) q.push(x);
        }
    }
    for(int i = 1; i <= n; i++) {
        if(nodes[i] != 0) {
            return true;
        }
    }
    return false;
}