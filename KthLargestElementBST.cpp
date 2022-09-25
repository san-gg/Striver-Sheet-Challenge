#include <bits/stdc++.h>

int KthLargestNumber(TreeNode<int>* root, int k) 
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
            st.push(p->left);
        }
        else st.push(p->right);
    }
    if(x != k) return -1;
    auto p = st.top();
    return p->data;
}
