#include <bits/stdc++.h> 
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<int> distances(n+1, 1000000000);
    distances[src] = 0;
    for(int i = 1; i <= n-1; i++) {
        for(auto &p : edges) {
            if(distances[p[0]] == 1000000000) continue;
            if(distances[p[0]] + p[2] < distances[p[1]]) {
                distances[p[1]] = distances[p[0]] + p[2];
            }
        }
    }
    return distances[dest];
}