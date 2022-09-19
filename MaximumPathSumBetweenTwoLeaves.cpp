#include <bits/stdc++.h> 

long long maxSum(TreeNode<int> *root, long long &ms) {
    if(root == nullptr) return 0;
    long long lt = maxSum(root->left, ms);
    long long rt = maxSum(root->right, ms);
    if(root->left != nullptr && root->right != nullptr)
        ms = max(ms, lt + rt + root->val);
    return max(lt, rt) + root->val;
}

long long int findMaxSumPath(TreeNode<int> *root)
{
    long long ms = -1;
    maxSum(root, ms);
    return ms;
}

