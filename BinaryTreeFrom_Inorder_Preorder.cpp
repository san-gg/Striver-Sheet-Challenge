#include <bits/stdc++.h>
typedef vector<int> vi;

int getPos(vi &inor, int x1, int x2, int tar) {
    while(x1 <= x2) {
        if(inor[x1] == tar) return x1;
        ++x1;
    }
    return -1;
}

TreeNode<int>* createTree(vi &inorder, vi &preorder, int &pos, int x1, int x2) {
    if(x1 > x2) return nullptr;
    pos += 1;
    TreeNode<int>* root = new TreeNode<int>(preorder[pos]);
    int p = getPos(inorder, x1, x2, preorder[pos]);
    root->left = createTree(inorder, preorder, pos, x1, p-1);
    root->right = createTree(inorder, preorder, pos, p+1, x2);
    return root;
}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
    vector<int> hs(inorder.size()+1, -1);
    int pos = -1;
    return createTree(inorder, preorder, pos, 0, inorder.size()-1);
}

