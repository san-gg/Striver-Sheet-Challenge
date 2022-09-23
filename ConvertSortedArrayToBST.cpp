#include <bits/stdc++.h>

TreeNode<int> *createBST(vector<int> &arr, int st, int end)
{
    if(st > end)
        return NULL;
    int mid = (st+end)/2;
    TreeNode<int> *curr = new TreeNode<int> (arr[mid]);
    
    curr->left = helper(arr, st, mid-1);
    curr->right = helper(arr, mid+1, end);
    
    return curr;
}

TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    if(n==0) return nullptr;
    return createBST(arr, 0, n-1);
}