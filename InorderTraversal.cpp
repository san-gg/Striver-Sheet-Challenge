/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/

void inorder(TreeNode *root, vector<int> &vec) {
    if(root == nullptr) return;
    inorder(root->left, vec);
    vec.push_back(root->data);
    inorder(root->right, vec);
}

vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    inorder(root, ans);
    return ans;
}