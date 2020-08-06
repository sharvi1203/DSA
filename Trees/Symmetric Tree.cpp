bool isSymUtil(struct Node* root1,struct Node* root2){
    if(root1==NULL && root2==NULL){
        return true;
    }
    if(root1==NULL || root2==NULL){
        return false;
    }
    if(root1->data!=root2->data){
        return false;
    }
    return isSymUtil(root1->left,root2->right)&&isSymUtil(root1->right,root2->left);
}
bool isSymmetric(struct Node* root)
{
    if(root==NULL){
        return true;
    }
    return isSymUtil(root->left,root->right);	
}
