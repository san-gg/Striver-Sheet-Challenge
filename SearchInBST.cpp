#include <bits/stdc++.h>

bool searchInBST(BinaryTreeNode<int> *root, int x) {
    while(root != nullptr) {
        if(root->data == x) return true;
        if(x < root->data) root = root->left;
        else if(x > root->data) root = root->right;
    }
    return false;
}