#include<bits/stdc++.h>
class TarjansAlgorithm {
    int n, ids;
    stack<int> st;
    vector<bool> presentOnStack;
    vector<bool> visited;
    vector<int> idsNode;
    vector<int> lowLinkId;
    unordered_map<int, vector<int>> adj;
public:
    TarjansAlgorithm(int nd, vector<vector<int>> &edges): n(nd), presentOnStack(nd+1,false),
                            visited(nd+1, false), idsNode(nd+1, -1), lowLinkId(nd+1, -1),
                            ids(0)
    {
        for(auto &p : edges) {
            adj[p[0]].push_back(p[1]);
        }
    }
    void findDFS(int currNode, vector<vector<int>> &ans) {
        st.push(currNode);
        presentOnStack[currNode] = true;
        visited[currNode] = true;
        idsNode[currNode] = lowLinkId[currNode] = ids++;
        for(int nextNode : adj[currNode]) {
            if(!visited[nextNode]) findDFS(nextNode, ans);
            if(presentOnStack[nextNode])
                lowLinkId[currNode] = min(lowLinkId[currNode], lowLinkId[nextNode]);
        }
        if(idsNode[currNode] == lowLinkId[currNode]) {
            // Root of SSC
            vector<int> printSSC;
            while(true) {
                int node = st.top(); st.pop();
                printSSC.push_back(node);
                presentOnStack[node] = false;
                lowLinkId[node] = lowLinkId[currNode];
                if(node == currNode) break;
            }
            ans.push_back(printSSC);
        }
    }
    void getSSC(vector<vector<int>> &ans) {
        for(int i = 0; i < n; i++) {
            if(!this->visited[i])
                findDFS(i, ans);
        }
    }
};

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    vector<vector<int>> answer;
    TarjansAlgorithm algo(n, edges);
    algo.getSSC(answer);
    return answer;
}