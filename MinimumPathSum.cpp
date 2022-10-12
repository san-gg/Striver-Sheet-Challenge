#include <bits/stdc++.h>
typedef vector<int> vi;

int recurse(vector<vi> &grid, int x1, int x2, int n, int m) {
    if(x1 == n || x2 == m) return INT_MAX;
    if(grid[x1][x2] <= 0) return -grid[x1][x2];
    int l1 = recurse(grid, x1, x2 + 1, n, m);
    int l2 = recurse(grid, x1 + 1, x2, n, m);
    int ml = min(l1, l2) + grid[x1][x2];
    grid[x1][x2] = -ml;
    return ml;
}
int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    grid[n-1][m-1] = -grid[n-1][m-1];
    return recurse(grid, 0, 0, n, m);
}