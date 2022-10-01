#include<bits/stdc++.h>
bool BFS(int m, vector<vector<int>> &edges, int nd, int color, vector<int> &visited) {
    queue<pair<int,int>> q;
    q.push({nd, color});
    while(!q.empty()) {
        auto p = q.front(); q.pop();
        visited[p.first] = 1;
        color = (p.second == 2) ? 3 : 2;
        for(int i = 0; i < m; i++) {
            if(edges[p.first][i] == 1) {
                q.push({i, color});
                edges[p.first][i] = color;
                edges[i][p.first] = p.second;
            }
            else if(edges[p.first][i] == p.second)
                return false;
        }
    }
    return true;
}

bool isGraphBirpatite(vector<vector<int>> &edges) {
    int n = edges.size();
    int m = edges[0].size();
    vector<int> visited(n, 0);
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            if(!BFS(m, edges, i, 2, visited))
                return false;
        }
    }

    return true;
}