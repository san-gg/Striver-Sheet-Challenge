#include <bits/stdc++.h> 

typedef unordered_map<int, pair<graphNode*,graphNode*>> umap;
typedef vector<graphNode*> vgraph;
void dfs(graphNode *node, vgraph &cloneNeighbour, umap &visited) {
    auto found = visited.find(node->data);
    if(found != visited.end()) {
        cloneNeighbour.push_back(found->second.second);
    }
    else {
        auto newNode = new graphNode(node->data);
        visited[node->data] = {node, newNode};
        cloneNeighbour.push_back(newNode);
        for(auto p : node->neighbours) {
            dfs(p, newNode->neighbours, visited);
        }
    }
}

graphNode *cloneGraph(graphNode *node)
{
    umap visited;
    umap clonevisited;
    if(node == nullptr) return nullptr;
    graphNode *cloneNode = new graphNode(node->data);
    visited[node->data] = {node, cloneNode};
    for(auto p : node->neighbours) {
        dfs(p, cloneNode->neighbours, visited);
    }
    return cloneNode;
}