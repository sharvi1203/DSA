int util(Node* node){
     if(node==NULL){
        return 0;
    }
    if(node->left==NULL && node->right==NULL){
        return 1;
    }
    int l=util(node->left);
    int r=util(node->right);
    return max(l,r)+1;
}
/* Computes the diameter of binary tree with given root.  */
int diameter(Node* node) {
   if(node==NULL){
       return 0;
   }
   int l=util(node->left);
   int r=util(node->right);
   return max(l+r+1,max(diameter(node->left),diameter(node->right)));
}
