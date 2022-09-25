#include <bits/stdc++.h> 

int kthSmallest(TreeNode<int> *root, int k)
{
    stack<TreeNode<int>*> st;
    int x = 0;
    st.push(root);
    while(!st.empty()) {
        auto p = st.top();
        if(p == nullptr) {
            st.pop();
            if(st.empty()) break;
            x += 1;
            if(x == k) break;
            p = st.top();
            st.pop();
            st.push(p->right);
        }
        else st.push(p->left);
    }
    if(x != k) return -1;
    auto p = st.top();
    return p->data;
}