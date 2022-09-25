#include <bits/stdc++.h> 

void inorder(BinaryTreeNode<int> *root, vector<int> &arr) {
    if(root == nullptr) return;
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}
pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    pair<int,int> p;
    if(root == nullptr) return p;
    vector<int> arr;
    inorder(root, arr);

    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] == key) {
            if(i-1 == -1) p.first = -1;
            else p.first = arr[i-1];
            if(i+1 == arr.size()) p.second = -1;
            else p.second = arr[i+1];
            break;
        }
    }
    return p;
}
