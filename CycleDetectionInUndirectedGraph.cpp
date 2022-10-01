typedef vector<vector<int>> vvi;
bool DFS(int E, vvi &edges, vector<bool> &visited, int nd, int p) {
   if(visited[nd]) return true;
    visited[nd] = true;
    for(int i = 0 ; i < E; i++) {
        if(edges[i][0] == nd && edges[i][1] != p) {
            if(DFS(E, edges, visited, edges[i][1], edges[i][0]))
                return true;
        }
        else if(edges[i][1] == nd && edges[i][0] != p) {
            if(DFS(E, edges, visited, edges[i][0], edges[i][1]))
                return true;
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    string s = "No";
    vector<bool> visited(n+1, false);
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            if(DFS(m, edges, visited, i, -1)) {
                s = "Yes";
                break;
            }
        }
    }
    return s;
}
