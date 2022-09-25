#include <bits/stdc++.h>
int next(stack<BinaryTreeNode<int>*> &st, BinaryTreeNode<int>* root){
    BinaryTreeNode<int>* curr = st.top(); st.pop();
    int x = curr -> data;
    if (curr -> right == NULL) return x;
    curr = curr -> right;
    while (curr){
        st.push(curr);
        curr = curr -> left;
    }
    return x;
}
int before(stack<BinaryTreeNode<int>*> &st, BinaryTreeNode<int>* root){
    BinaryTreeNode<int>* curr = st.top(); st.pop();
    int x = curr -> data;
    if (curr -> left == NULL) return x;
    curr = curr -> left;
    while (curr){
        st.push(curr);
        curr = curr -> right;
    }
    return x;
}
bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    stack<BinaryTreeNode<int>*> nst, bst;
        
    BinaryTreeNode<int>* curr = root ;
    while (curr){
        nst.push(curr);
        curr = curr -> left;
    }
    curr = root ;
    while (curr){
        bst.push(curr);
        curr = curr -> right;
    }
    int i = next(nst, root);
    int j = before(bst, root);
    while (i != j){
        int sum = i + j;
        if (sum == k) return true;
        else if (sum < k){
            i = next(nst, root);
        }else{
            j = before(bst, root);
        }
    }
    return false;
}