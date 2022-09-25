#include <bits/stdc++.h>

class BSTiterator
{
    stack<TreeNode<int>*> st;
public:
    BSTiterator(TreeNode<int> *root)
    {
        while(root != nullptr) {
            st.push(root);
            root = root->left;
        }
    }

    int next()
    {
        TreeNode<int>* val = st.top();
        TreeNode<int>* tmp = val;
        st.pop();
        tmp = tmp->right;
        while(tmp != nullptr) {
            st.push(tmp);
            tmp = tmp->left;
        }
        
        return val->data;
    }

    bool hasNext()
    {
        return !st.empty();
    }
};