#include<bits/stdc++.h>
const vector<pair<int,int>> pos = {{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{1,1},{-1,1},{1,-1}};
void BFS(int** arr, int n, int m, pair<int, int> loc) {
    queue<pair<int, int>> q;
    q.push(loc);
    while(!q.empty()) {
        auto p = q.front(); q.pop();
        int r = p.first, c = p.second;
        arr[r][c] = 0;
        for(auto &s : pos) {
            int r1 = r + s.first, c1 = c + s.second;
            if(r1 >= 0 && c1 >= 0 && r1 < n && c1 < m && arr[r1][c1] == 1) {
                arr[r1][c1] = 2;
                q.push({r1, c1});
            }
        }
    }
}

int getTotalIslands(int** arr, int n, int m)
{
    int lands = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr[i][j] == 1) {
                lands += 1;
                BFS(arr, n, m, {i, j});
            }
        }
    }
    return lands;
}
