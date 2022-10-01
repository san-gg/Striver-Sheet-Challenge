#include <bits/stdc++.h> 
bool cmp(const vector<int> &x1, const vector<int> &x2) {
    return x1[2] < x2[2];
}

bool isCycle(vector<int> &idList, int x, int y) {
    return idList[x] == idList[y];
}

void assignIds(vector<int> &idList, int &ids, int x, int y) {
    if(idList[x] == -1 && idList[y] == -1) {
        idList[x] = idList[y] = ids++;
    }
    else if(idList[x] != -1 && idList[y] != -1) {
        int minId = min(idList[x], idList[y]);
        int maxId = max(idList[x], idList[y]);
        for(int i = 0; i < idList.size(); i++) {
            if(idList[i] == maxId)
                idList[i] = minId;
        }
    }
    else {
        int id = max(idList[x], idList[y]);
        idList[x] = idList[y] = id;
    }
}

int kruskalMST(int n, int m, vector<vector<int>> &graph) {
    int ans = 0;
    int ids = 0;
    vector<bool> visited(n+1, false);
    vector<int> idList(n+1, -1);
    sort(graph.begin(), graph.end(), cmp);
    for(auto &p : graph) {
        if(p[0] == p[1]) continue; // Ignore self loop
        if(!visited[p[0]] || !visited[p[1]]) {
            visited[p[0]] = true;
            visited[p[1]] = true;
            ans += p[2];
            assignIds(idList, ids, p[0], p[1]);
        }
        else if(!isCycle(idList, p[0], p[1])) {
            ans += p[2];
            assignIds(idList, ids, p[0], p[1]);
        }
    }
    return ans;
}