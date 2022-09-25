#include <bits/stdc++.h>

TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
    while(root != nullptr) {
        if(root->data == P->data || root->data == Q->data) break;
        else if( (P->data < root->data && Q->data > root->data) ||
               (P->data > root->data && Q->data < root->data) ) {
            break;
        }
        if(P->data < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return root;
}
