#include <bits/stdc++.h> 
typedef pair<int,int> pi;
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    vector<int> distances(vertices, INT_MAX);
    unordered_map<int, vector<pi>> adj;
    for(auto &p : vec) {
        adj[p[0]].push_back({p[1],p[2]});
        adj[p[1]].push_back({p[0],p[2]});
    }
    distances[source] = 0;
    pq.push({0, source});
    while(!pq.empty()) {
        auto &p = pq.top();
        int prevDistance = p.first;
        int currNode = p.second;
        pq.pop();
        for(auto &nextNode : adj[currNode]) {
            if(distances[nextNode.first] > (prevDistance + nextNode.second)) {
                distances[nextNode.first] = prevDistance + nextNode.second;
                pq.push(make_pair(distances[nextNode.first], nextNode.first));
            }
        }
    }

    return distances;
}
