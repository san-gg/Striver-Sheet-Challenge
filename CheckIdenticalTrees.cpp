#include <bits/stdc++.h> 

bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    if(root1 == nullptr && root2 == nullptr) return true;
    else if(!(root1 != nullptr && root2 != nullptr)) return false;
    if(root1->data != root2->data) return false;
    if(!identicalTrees(root1->left, root2->left)) return false;
    if(!identicalTrees(root1->right, root2->right)) return false;
    return true;
}

