typedef vector<vector<int>> vvi;

void DFS(int V, int E, vvi &edges, vector<int> &ans, vector<bool> &visited, int nd) {
    if(visited[nd]) return;
    visited[nd] = true;
    ans.push_back(nd);
    for(int i = 0; i < E; i++) {
        if(edges[i][0] == nd) {
            DFS(V, E, edges, ans, visited, edges[i][1]);
        }
        else if(edges[i][1] == nd) {
            DFS(V, E, edges, ans, visited, edges[i][0]);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<int>> ans1;
    vector<bool> visited(V, false);
    for(int i = 0; i < V; i++) {
        if(visited[i] == false) {
            vector<int> ans;
            DFS(V, E, edges, ans, visited, i);
            ans1.push_back(ans);
        }
    }
    for(auto &p : ans1) {
        sort(p.begin(), p.end());
    }
    return ans1;
}