Node*  minValue(Node* node){
    Node* current=node;
    while(current->left!=NULL){
        current=current->left;
    }
    return current;
}
Node * inOrderSuccessor(Node *root, Node *x)
{
    if(x->right!=NULL){
        return minValue(x->right);
    }
    Node* succ=NULL;
    while(root!=NULL){
        if(x->data<root->data){
            succ=root;
            root=root->left;
        }else if(x->data > root->data){
            root=root->right;
        }else{
            break;
        }
    }
    return succ;
}
