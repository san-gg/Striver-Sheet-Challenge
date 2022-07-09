void solve(int col, vector<vector<int>> &board, vector<int> &left, vector<int> &d1, vector<int> &d2, vector<vector<int>> &ans) {
    if(col == left.size()) {
        vector<int> tmp;
        for(auto &x : board)
            tmp.insert(tmp.end(), x.begin(), x.end());
        ans.push_back(tmp);
    }
    for(int i = 0; i < left.size(); i++) {
        if(left[i] != 1 && d1[col+i] != 1 && d2[left.size() - 1 + col - i] != 1 && board[i][col] != 1) {
            left[i] = 1;
            d1[col+i] = 1;
            d2[left.size() - 1 + col - i] = 1;
            board[i][col] = 1;
            solve(col+1, board, left, d1, d2, ans);
            board[i][col] = 0;
            left[i] = 0;
            d1[col+i] = 0;
            d2[left.size() - 1 + col - i] = 0;
        }
    }
}
vector<vector<int>> solveNQueens(int n) {
    vector<vector<int>> board(n);
    vector<int> left(n, 0);
    vector<int> d1(2*n - 1);
    vector<int> d2(2*n - 1);
    vector<int> tmp(n, 0);
    vector<vector<int>> ans;
    for(int i = 0; i < n; i++)
        board[i] = tmp;
    solve(0, board, left, d1, d2, ans);
    return ans;
}