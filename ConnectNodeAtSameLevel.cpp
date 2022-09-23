#include <bits/stdc++.h> 

void connectNodes(BinaryTreeNode< int > *root) {
    queue<BinaryTreeNode<int>*> q;
    int count = 0;
    int prevCount = 1;
    int x = 0;
    BinaryTreeNode<int>* tmp = nullptr;
    q.push(root);
    while(!q.empty()) {
        auto p = q.front(); q.pop();
        ++x;
        if(tmp != nullptr) tmp->next = p;
        if(p->left != nullptr) {
            count += 1;
            q.push(p->left);
        }
        if(p->right != nullptr) {
            count += 1;
            q.push(p->right);
        }
        if(x == prevCount) {
            prevCount = count;
            count = 0;
            x = 0;
            p = nullptr;
        }
        tmp = p;
    }
}

