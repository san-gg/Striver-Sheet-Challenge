#include <bits/stdc++.h>

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    vector<int>ans;
    vector<bool>visited(vertex);   
    set<int>adj[vertex]; 
    for(auto &i : edges){
        adj[i.first].insert(i.second);
        adj[i.second].insert(i.first);
    }
    for(int i = 0; i < vertex; i++){
        if(!visited[i]){
            queue<int>q;
            q.push(i);
            visited[i] = 1;
            while(!q.empty()){
                int front = q.front(); q.pop();
                ans.push_back(front);
                for(auto &i : adj[front]){
                    if(!visited[i]){
                        q.push(i);
                        visited[i] = 1;
                    }
                }
            }
        }
    }
    return ans;
}