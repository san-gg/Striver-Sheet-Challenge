/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

void inorder(TreeNode<int> *root, vector<int> &vec, int &mht, int ht) {
    if(root == nullptr) return;
    if(ht > mht) vec.push_back(root->data);
    inorder(root->left, vec, mht, ht+1);
    mht = max(mht, ht);
    inorder(root->right, vec, mht, ht+1);
}

vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int> ans;
    int mht = 0;
    inorder(root, ans, mht, 1);
    return ans;
}