int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<vector<int>> memo(n+1, vector<int>(n+1, 1000000000));
    for(int i = 0; i < m; i++) {
        auto &p = edges[i];
        memo[p[0]][p[1]] = p[2];
    }
    for(int i = 1; i <= n; i++) memo[i][i] = 0;
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(memo[i][k] == 1000000000 || memo[k][j] == 1000000000)
                    continue;
                if(memo[i][j] > memo[i][k] + memo[k][j]) {
                    memo[i][j] = memo[i][k] + memo[k][j];
                }
            }
        }
    }
    return memo[src][dest];
}