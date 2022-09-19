typedef BinaryTreeNode<int>* bt;
bool equals(bt t1, bt t2) {
    if(t1 == nullptr && t2 == nullptr) return true;
    else if(!(t1 != nullptr && t2 != nullptr)) return false;
    else if(t1->data != t2->data) return false;
    return true;
}
bool check(bt left, bt right, bool &ret) {
    if(!equals(left, right)) {
        ret = false;
        return false;
    }
    if(left == nullptr) return true;
    check(left->left, right->right, ret);
    if(ret == false) return false;
    check(left->right, right->left, ret);
    if(ret == false) return false;
    return true;
}

bool isSymmetric(BinaryTreeNode<int>* root)
{
    if(root == nullptr) return true;
    else if(!(root->left != nullptr && root->right != nullptr))
        return false;
    bool ret = true;
    return check(root->left, root->right, ret);
}