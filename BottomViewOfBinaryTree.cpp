/*************************************************************
 
    Following is the Binary Tree node structure.

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void inorder(BinaryTreeNode<int> * root, map<int, pair<int, int>> &btm, int ht, int d) {
    if(root == nullptr) return;
    inorder(root->left, btm, ht+1, d-1);
    auto x = btm.find(d);
    if(x != btm.end() && x->second.first <= ht) {
        x->second.first = ht;
        x->second.second = root->data;
    }
    else if(x == btm.end()) {
        btm[d] = {ht, root->data};
    }
    inorder(root->right, btm, ht+1, d+1);
    return;
}

vector<int> bottomView(BinaryTreeNode<int> * root) {
    map<int, pair<int, int>> bottom;
    inorder(root, bottom, 1, 0);
    vector<int> answer;
    for(auto &p : bottom) {
        answer.push_back(p.second.second);
    }
    return answer;
}