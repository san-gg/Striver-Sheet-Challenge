#include <map>
#include <queue>
vector<int> verticalOrderTraversal(TreeNode<int> *root) {
    map<int, vector<int>> order;
    queue<pair<TreeNode<int>*, int>> q;
    q.push({root, 0});
    while(!q.empty()) {
        TreeNode<int> *tmp = q.front().first;
        int d = q.front().second;
        q.pop();
        order[d].push_back(tmp->data);
        if(tmp->left != nullptr)
            q.push({tmp->left, d-1});
        if(tmp->right != nullptr)
            q.push({tmp->right, d+1});
    }
    vector<int> answer;
    for(auto &p : order) {
        answer.insert(answer.end(), p.second.begin(), p.second.end());
    }
    return answer;
}