#include <bits/stdc++.h>

int floorInBST(TreeNode<int> * root, int x)
{
    int floor = root->val;
    while(root != nullptr) {
        if(root->val == x) {
            floor = x;
            break;
        }
        else if(x < root->val) root = root->left;
        else {
            floor = root->val;
            root = root->right;
        }
    }
    return floor;
}