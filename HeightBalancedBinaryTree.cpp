int bfs(BinaryTreeNode<int> *root, bool &ret) {
    if(root == nullptr) return 0;
    int lht = bfs(root->left, ret);
    if(ret) return 0;
    int rht = bfs(root->right, ret);
    if(ret) return 0;
    
    if(abs(lht - rht) > 1) ret = true;
    return max(lht, rht) + 1;
}

bool isBalancedBT(BinaryTreeNode<int>* root) {
    bool ret = false;
    bfs(root, ret);
    return !ret;
}