#include <bits/stdc++.h> 

void inorder(BinaryTreeNode<int> *root, vector<int> &arr) {
    if(root == nullptr) return;
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

bool validateBST(BinaryTreeNode<int> *root) {
    if(root == nullptr) return true;
    vector<int> arr;
    inorder(root, arr);
    int tmp = arr[0];
    for(int i = 1; i < arr.size(); i++) {
        if(tmp > arr[i]) return false;
        tmp = arr[i];
    }
    return true;
}

