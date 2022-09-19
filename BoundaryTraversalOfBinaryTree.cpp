#include <bits/stdc++.h>

void leftBoundary(TreeNode<int>* root, vector<int> &v) {
    if(root->left == nullptr && root->right == nullptr) return;
    v.push_back(root->data);
    if(root->left == nullptr)
        leftBoundary(root->right, v);
    else
        leftBoundary(root->left, v);
    return;
}

void rightBoundary(TreeNode<int>* root, vector<int> &v) {
    if(root->left == nullptr && root->right == nullptr) return;
    v.push_back(root->data);
    if(root->right == nullptr)
        rightBoundary(root->left, v);
    else
        rightBoundary(root->right, v);
    return;
}

void baseTree(TreeNode<int>* root, vector<int> &v) {
    if(root == nullptr) return;
    baseTree(root->left, v);
    baseTree(root->right, v);
    if(root->left == nullptr && root->right == nullptr)
        v.push_back(root->data);
    return;
}

vector<int> traverseBoundary(TreeNode<int>* root) {
    vector<int> base, left, right, ans;
    if(root->left != nullptr) leftBoundary(root->left, left);
    if(root->right != nullptr) rightBoundary(root->right, right);
    if(root->left != nullptr || root->right != nullptr)
        ans.push_back(root->data);
    baseTree(root, base);
    reverse(right.begin(), right.end());
    
    ans.insert(ans.end(), left.begin(), left.end());
    ans.insert(ans.end(), base.begin(), base.end());
    ans.insert(ans.end(), right.begin(), right.end());
    return ans;
}
