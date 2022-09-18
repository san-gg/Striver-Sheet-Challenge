int bfs(TreeNode<int> *root, int &d) {
    if(root == nullptr) return 0;
    int lht = bfs(root->left, d);
    int rht = bfs(root->right, d);
    d = max(d, lht + rht);
    return max(lht, rht) + 1;
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
    int diameter = 0;
    bfs(root, diameter);
    return diameter;
}
