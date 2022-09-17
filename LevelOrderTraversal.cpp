vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    if(root == nullptr) return {};
    vector<int> ans;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        auto p = q.front();
        q.pop();
        if(p->left != nullptr) q.push(p->left);
        if(p->right != nullptr) q.push(p->right);
        ans.push_back(p->val);
    }
    return ans;
}