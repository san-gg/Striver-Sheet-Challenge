/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/
void postorder(BinaryTreeNode<int> *root, vector<int> &v) {
    if(root == nullptr) return;
    postorder(root->left, v);
    postorder(root->right, v);
    v.push_back(root->data);
    return;
}

void preorder(BinaryTreeNode<int> *root, vector<int> &v) {
    if(root == nullptr) return;
    v.push_back(root->data);
    preorder(root->left, v);
    preorder(root->right, v);
    return;
}

void inorder(BinaryTreeNode<int> *root, vector<int> &v) {
    if(root == nullptr) return;
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
    return;
}

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root) {
    vector<vector<int>> answer;
    vector<int> inorder_v;
    vector<int> preorder_v;
    vector<int> postorder_v;
    inorder(root, inorder_v);
    preorder(root, preorder_v);
    postorder(root, postorder_v);
    answer.push_back(inorder_v);
    answer.push_back(preorder_v);
    answer.push_back(postorder_v);
    return answer;
}