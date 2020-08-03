//is mei tum har node ke left aur right ko compare kroge toh partial hoga from root vertex tumko check krna hai ki to the left sari use choti hai ya nhi ||ly with right side.
bool isBST(Node* root,int max,int min){
    if(root==NULL){
        return true;
    }
    if(root->data<=min || root->data>=max){
        return false;
    }
    return isBST(root->left,root->data,min)&& isBST(root->right,max,root->data);
}
bool isBST(Node* root) {
    return isBST(root,INT_MAX,INT_MIN);
}
