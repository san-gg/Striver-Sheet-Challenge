#include <bits/stdc++.h>

int findCeil(BinaryTreeNode<int> *node, int x){
    int ceil = node->data;
    while(node != nullptr) {
        if(node->data == x) {
            ceil = x;
            break;
        }
        else if(x < node->data) {
            ceil = node->data;
            node = node->left;
        }
        else node = node->right;
    }
    if(x > ceil) return -1;
    return ceil;
}