int height(Node* root){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        return 1;
    }
    int l=height(root->left);
    int r=height(root->right);
    return (l>r)?l+1:r+1;
}
bool isBalanced(Node *root)
{
    if(root==NULL){
        return true;
    }
    int l=height(root->left);
    int r=height(root->right);
    return abs(l-r)<=1 && isBalanced(root->left) && isBalanced(root->right);
}
