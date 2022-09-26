#include <bits/stdc++.h>

vector<int> inorder(TreeNode<int>* root, int &m) {
    if(root == nullptr) return {0, INT_MAX, INT_MIN};
    vector<int> a(3, -1);
    vector<int> sz1 = inorder(root->left, m);
    vector<int> sz2 = inorder(root->right, m);
    if(sz1[0] == -1 || sz2[0] == -1) return a;
    if(sz1[2] > root->data) return a;
    if(sz2[1] < root->data) return a;
    a[0] = sz1[0] + sz2[0] + 1;
    a[1] = min(sz1[1], sz2[1]);
    a[1] = min(a[1], root->data);
    a[2] = max(sz1[2], sz2[2]);
    a[2] = max(a[2], root->data);
    m = max(m, a[0]);
    return a;
}
int largestBST(TreeNode<int>* root) 
{
    int m = 0;
    inorder(root, m);
    return m;
}
