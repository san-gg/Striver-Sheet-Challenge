bool doColor(vector<vector<int>> &m, int n, vector<int> &nodes, int color) {
    int sz = m.size();
    for(int i = 0; i < sz; i++) {
        if(n != i && m[n][i] == 1 && nodes[i] == color)
            return false;
    }
    return true;
}

bool recurse(int n, vector<vector<int>> &mat, vector<int> &nodes, int sz, int m) {
    if(n == sz) return true;
    for(int i = 1; i <= m; i++) {
        if(doColor(mat, n, nodes, i)) {
            nodes[n] = i;
            if(recurse(n+1, mat, nodes, sz, m))
                return true;
            nodes[n] = 0;
        }
    }
    return false;
}

string graphColoring(vector<vector<int>> &mat, int m) {
    vector<int> nodes(mat.size(), 0);
    if(recurse(0, mat, nodes, mat.size(), m)) {
        return "YES";
    }
    return "NO";
}