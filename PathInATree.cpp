#include <bits/stdc++.h>
bool bfs(TreeNode<int> *root, vector<int> &v, int x) {
    if(root == nullptr) return false;
    if(root->data == x) {
        v.push_back(root->data);
        return true;
    }
    if(bfs(root->left, v, x)) {
        v.push_back(root->data);
        return true;
    }
    if(bfs(root->right, v, x)) {
        v.push_back(root->data);
        return true;
    }
    return false;
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    vector<int> ans;
    bfs(root, ans, x);
    reverse(ans.begin(), ans.end());
    return ans;
}
