#include <bits/stdc++.h>

void dfs(TreeNode<int> *root, string &s) {
    if(root == nullptr) {
        s.append(1, '#');
        return;
    }
    s.append(to_string(root->data));
    s.append(1, '|');
    bfs(root->left, s);
    bfs(root->right, s);
    return;
}
string serializeTree(TreeNode<int> *root)
{
    string serialize;
    bfs(root, serialize);
    return serialize;
}

int getPos(string &serialized, int &pos) {
    if(serialized[pos] == '#') {
        pos += 1;
        return -1;
    }
    return serialized.find('|', pos);
}

void dfs2(TreeNode<int>* root, string &serialized, int &pos) {
    int pos2 = getPos(serialized, pos);
    if(pos2 != -1) {
        root->left = new TreeNode<int>(stoi(serialized.substr(pos, pos2-pos)));
        pos = pos2 + 1;
        bfs2(root->left, serialized, pos);
    }
    pos2 = getPos(serialized, pos);
    if(pos2 != -1) {
        root->right = new TreeNode<int>(stoi(serialized.substr(pos, pos2-pos)));
        pos = pos2 + 1;
        bfs2(root->right, serialized, pos);
    }
    return;
}

TreeNode<int>* deserializeTree(string &serialized)
{
    TreeNode<int>* root = nullptr;
    int pos = serialized.find('|');
    if(pos == -1) return root;
    root = new TreeNode<int>(stoi(serialized.substr(0, pos)));
    pos += 1;
    bfs2(root, serialized, pos);
    return root;
}



