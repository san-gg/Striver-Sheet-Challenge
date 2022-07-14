vector<vector<int>> answer;
void recurse(vector<vector<int>> &mz, vector<vector<int>> mat, int r, int c, int n) {
    mat[r][c] = 1;
    if(r == n && c == n) {
        vector<int> all;
        for(vector<int> &x : mat)
            all.insert(all.end(), x.begin(), x.end());
        answer.push_back(all);
        return;
    }
    
    // left
    if(c - 1 >= 0 && mz[r][c-1] == 1 && mat[r][c-1] == 0)
        recurse(mz, mat, r, c - 1, n); 
    // right
    if(c + 1 <= n && mz[r][c+1] == 1 && mat[r][c+1] == 0)
        recurse(mz, mat, r, c + 1, n);
    // up
    if(r - 1 >= 0 && mz[r-1][c] == 1 && mat[r-1][c] == 0)
        recurse(mz, mat, r - 1, c, n);
    // down
    if(r + 1 <= n && mz[r+1][c] == 1 && mat[r+1][c] == 0)
        recurse(mz, mat, r + 1, c, n);
    
    return;
}

vector<vector<int>> ratInAMaze(vector<vector<int>> &maze, int n) {
    answer.clear();
    vector<vector<int>> mat;
    for(int i = 0; i < n; i++) mat.push_back(vector<int>(n, 0));
    recurse(maze, mat, 0, 0, n - 1);
    return answer;
}