#include <bits/stdc++.h> 

void append(TreeNode<int> *lt, TreeNode<int> *rt) {
    TreeNode<int> *tmp = lt;
    lt = lt->right;
    while(lt != nullptr) {
        tmp = tmp->right;
        lt = lt->right;
    }
    tmp->right = rt;
}

TreeNode<int>* preorder(TreeNode<int> *root) {
    if(root == nullptr) return nullptr;
    TreeNode<int>* lt = preorder(root->left);
    TreeNode<int>* rt = preorder(root->right);
    root->left = nullptr;
    root->right = nullptr;
    if(lt != nullptr) root->right = lt;
    if(rt != nullptr) append(root, rt);
    return root;
}
TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    preorder(root);
    return root;
}