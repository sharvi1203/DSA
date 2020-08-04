Node* global=NULL;
Node* LCA(Node *root, int n1, int n2)
{                                 
   if(root==NULL){
       return NULL;
   }
   Node *ans=NULL,*ans1=NULL;
   ans=LCA(root->left,n1,n2);
   ans1=LCA(root->right,n1,n2);
      if(root->data==n1){
          ans=root;
      }
      if(root->data==n2){
          ans1=root;
      }
      if(ans==NULL && ans1==NULL){
           return NULL;
      }
      if(ans==NULL && ans1!=NULL){
          return ans1;
      }
      if(ans!=NULL && ans1==NULL){
          return ans;
      }
      if(ans!=NULL && ans1!=NULL){
          global=root;
          return global;
      }
    
}
