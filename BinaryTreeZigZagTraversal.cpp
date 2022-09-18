#include <stack>
typedef stack<BinaryTreeNode<int>*> sbt;

void zigzag(int rev, sbt &src, sbt &dest, vector<int> &ans) {
    while(!src.empty()) {
        auto p = src.top(); src.pop();
        ans.push_back(p->data);
        if(rev) {
            if(p->right != nullptr) dest.push(p->right);
            if(p->left != nullptr) dest.push(p->left);
        }
        else {
            if(p->left != nullptr) dest.push(p->left);
            if(p->right != nullptr) dest.push(p->right);
        }
    }
}

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    sbt zig;
    sbt zag;
    vector<int> answer;
    if(root == nullptr) return {};
    zig.push(root);
    while(!zig.empty() || !zag.empty()) {
        if(!zig.empty()) zigzag(0, zig, zag, answer);
        else if (!zag.empty()) zigzag(1, zag, zig, answer);
    }
    return answer;
}
