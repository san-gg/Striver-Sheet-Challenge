#include <bits/stdc++.h> 

void doChangeNode(BinaryTreeNode < int > * root) {
    int sum = 0;
    if(root->left != nullptr) sum = sum + root->left->data;
    if(root->right != nullptr) sum = sum + root->right->data;
    
    if(root->data == sum) return;
    else if(root->data < sum) root->data = sum;
    else if(root->left != nullptr && root->right != nullptr) {
        int x = root->data - sum;
        int d = x / 2;
        root->left->data += d;
        root->right->data += d + x % 2;
    }
    else if(root->left != nullptr) root->left->data = root->data;
    else if(root->right != nullptr) root->right->data = root->data;
    return;
}

void changeTree(BinaryTreeNode < int > * root) {
    if(root == nullptr) return;
    doChangeNode(root);
    changeTree(root->left);
    changeTree(root->right);
    doChangeNode(root);
}


