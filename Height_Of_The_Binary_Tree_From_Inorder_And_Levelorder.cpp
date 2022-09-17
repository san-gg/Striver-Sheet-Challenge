#include <queue>
int heightOfTheTree(vector<int>& inorder, vector<int>& levelOrder, int N){
    vector<int> pos(N+1, 0);
    queue<vector<int>> q;
    for(int i = 0; i < N; i++) pos[inorder[i]] = i;
    q.push({0, N-1, 0});
    int maxHeight = 0;
    for(int currPos = 0; currPos < N; currPos++) {
        auto p = q.front(); q.pop();
        int left = p[0];
        int right = p[1] ;
        int ht = p[2];
        int nextElement = pos[levelOrder[currPos]];
        
        maxHeight = max(maxHeight, ht);
        if(nextElement > left) {
            q.push({left, nextElement-1, ht+1});
        }
        if(nextElement < right) {
            q.push({nextElement+1, right, ht+1});
        }
    }
    return maxHeight;
}