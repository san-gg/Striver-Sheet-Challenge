#include <bits/stdc++.h> 

TreeNode<int>* addBst(TreeNode<int>* node, int val) {
    while(true) {
        if(val == node->data) return node;
        else if(val < node->data) {
            if(node->left == nullptr) {
                node->left = new TreeNode<int>(val);
                return node->left;
            }
            node = node->left;
        }
        else {
            if(node->right == nullptr) {
                node->right = new TreeNode<int>(val);
                return node->right;
            }
            node = node->right;
        }
    }
}

TreeNode<int>* preOrderTree(vector<int> &preOrder){
    vector<TreeNode<int>*> nodes(preOrder.size(), nullptr);
    vector<int> pos(preOrder.size(), -1);
    pos[0] = -2;
    nodes[0] = new TreeNode<int>(preOrder[0]);
    for(int i = 1; i < preOrder.size(); i++) {
        int x = i - 1;
        while(pos[x] != -2) {
            if(preOrder[x] >= preOrder[i]) break;
            x = pos[x];
        }
        pos[i] = x;
        nodes[i] = addBst(nodes[x], preOrder[i]);
    }
    
    return nodes[0];
}



