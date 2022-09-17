/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include <map>
void inorder(TreeNode<int> * root, map<int, pair<int, int>> &btm, int ht, int d) {
    if(root == nullptr) return;
    inorder(root->left, btm, ht+1, d-1);
    auto x = btm.find(d);
    if(x != btm.end() && x->second.first >= ht) {
        x->second.first = ht;
        x->second.second = root->val;
    }
    else if(x == btm.end()) {
        btm[d] = {ht, root->val};
    }
    inorder(root->right, btm, ht+1, d+1);
    return;
}

vector<int> getTopView(TreeNode<int> *root) {
    map<int, pair<int, int>> bottom;
    inorder(root, bottom, 1, 0);
    vector<int> answer;
    for(auto &p : bottom) {
        answer.push_back(p.second.second);
    }
    return answer;
}