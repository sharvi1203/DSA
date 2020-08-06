Node* util(Node* root){
    if(root==NULL){
        return root;
    }
    if(root->left!=NULL){
        Node* left=util(root->left);
        for(;left->right!=NULL;left=left->right);
        left->right=root;
        root->left=left;
    }
    if(root->right!=NULL){
        Node* right=util(root->right);
        for(;right->left!=NULL;right=right->left);
        right->left=root;
        root->right=right;
    }
    return root;
}

Node * bToDLL(Node *root)
{
    if(root==NULL){
        return root;
    }
    root=util(root);
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}

