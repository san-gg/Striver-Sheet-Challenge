#include <queue>
int minTimeToRot(vector<vector<int>>& grid, int n, int m) {
    queue<pair<int, int>> qu;
    int rotten = 0;
    int countRotten = 0;
    int fresh = 0;
    int ans = 0;
    // count all the fresh
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 1) ++fresh;
            else if(grid[i][j] == 2) {
                ++rotten;
                qu.push({i, j});
            }
        }
    }
    // calculation
    while(!qu.empty() && fresh != 0) {
        countRotten = 0;
        while(rotten-- && fresh != 0) {
            int i = qu.front().first;
            int j = qu.front().second;
            qu.pop();
            // up
            if(i - 1 >= 0 && grid[i - 1][j] == 1) {
                --fresh; ++countRotten; qu.push({i-1, j});
                grid[i - 1][j] = 2;
            }
            // down
            if(i + 1 < n && grid[i + 1][j] == 1) {
                --fresh; ++countRotten; qu.push({i+1, j});
                grid[i + 1][j] = 2;
            }
            // left
            if(j - 1 >= 0 && grid[i][j - 1] == 1) {
                --fresh; ++countRotten; qu.push({i, j-1});
                grid[i][j - 1] = 2;
            }
            // right
            if(j + 1 < m && grid[i][j + 1] == 1) {
                --fresh; ++countRotten; qu.push({i, j+1});
                grid[i][j + 1] = 2;
            }
        }
        ++ans;
        rotten = countRotten;
    }
    return fresh == 0 ? ans : -1;
}