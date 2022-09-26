#include <bits/stdc++.h>

BinaryTreeNode<int>* goRight(BinaryTreeNode<int>* node) {
    BinaryTreeNode<int>* tmp = node;
    while(node != nullptr) {
        tmp = node;
        node = node->right;
    }
    return tmp;
}
BinaryTreeNode<int>* goLeft(BinaryTreeNode<int>* node) {
    BinaryTreeNode<int>* tmp = node;
    while(node != nullptr) {
        tmp = node;
        node = node->left;
    }
    return tmp;
}
BinaryTreeNode<int>* inorder(BinaryTreeNode<int>* root) {
    if(root == nullptr) return nullptr;
    BinaryTreeNode<int>* tmp1 = goRight(inorder(root->left));
    if(tmp1 != nullptr) {
        tmp1->right = root;
        root->left = tmp1;
    }
    BinaryTreeNode<int>* tmp2 = goLeft(inorder(root->right));
    if(tmp2 != nullptr) {
        tmp2->left = root;
        root->right = tmp2;
    }
    return root;
}

BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    root = goLeft(inorder(root));
    return root;
}