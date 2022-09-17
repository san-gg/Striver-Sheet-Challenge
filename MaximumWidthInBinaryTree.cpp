int getMaxWidth(TreeNode<int> *root)
{
    if(root == nullptr) return 0;
    int maxLength = 0;
    int x = 0;
    int prev = 0;
    queue<pair<TreeNode<int>*, int>> q;
    q.push({root, 1});
    while(!q.empty()) {
        auto p = q.front();
        int ht = p.second;
        q.pop();
        if(p.first->left != nullptr) q.push({p.first->left, ht+1});
        if(p.first->right != nullptr) q.push({p.first->right, ht+1});
        
        if(prev != ht) {
            maxLength = max(maxLength, x);
            x = 0;
            prev = ht;
        }
        ++x;
    }
    maxLength = max(maxLength, x);
    return maxLength;
}