#include <bits/stdc++.h> 
void setZeros(vector<vector<int>> &matrix) {
    unordered_set<int> dp_row, dp_col;
    int row = matrix.size();
    int col = matrix[0].size();
    vector<pair<int,int>> noZeros;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(matrix[i][j] == 0)
                noZeros.push_back({i,j});
        }
    }
    for(auto &p : noZeros) {
        auto r = dp_row.find(p.first);
        auto c = dp_col.find(p.second);
        if(r == dp_row.end()) {
            dp_row.insert(p.first);
            for(int i = 0; i < col; i++)
                matrix[p.first][i] = 0;
        }
        if(c == dp_col.end()) {
            dp_col.insert(p.second);
            for(int i = 0; i < row; i++)
                matrix[i][p.second] = 0;
        } 
    }
}
//codestudio