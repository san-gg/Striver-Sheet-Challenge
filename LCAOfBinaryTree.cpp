#include <bits/stdc++.h> 
int bfs(TreeNode<int> *root, int x, int y, bool &ret) {
    if(root == nullptr) return -1;
    int x1 = bfs(root->left, x, y, ret);
    if(ret) return x1;
    int y1 = bfs(root->right, x, y, ret);
    if(ret) return y1;
    if(x1 != -1 && y1 != -1) {
        ret = true;
        return root->data;
    }
    else if((x1 != -1 || y1 != -1) && (root->data == x || root->data == y)) {
        ret = true;
        return root->data;
    }
    if(root->data == x || root->data == y) return root->data;
    return x1 != -1 ? x1 : y1 != -1 ? y1 : -1;
}

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
    bool ret = false;
    return bfs(root, x, y, ret);
}