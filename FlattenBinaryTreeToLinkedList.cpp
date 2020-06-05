/*
  Given a binary tree, flatten it to a linked list in-place.

  Example :
  Given


           1
          / \
         2   5
        / \   \
       3   4   6
  The flattened tree should look like:

     1
      \
       2
        \
         3
          \
           4
            \
             5
              \
               6
  Note that the left child of all nodes should be NULL.
  */
  /**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::flatten(TreeNode* A) {
     if(A==NULL){
         return NULL;
     }
     if(A->left==NULL && A->right==NULL){
         return A;
     }
     TreeNode* leftLL=flatten(A->left);
     TreeNode* rightLL=flatten(A->right);
     if(leftLL){
         TreeNode* temp=leftLL;
         while(temp->right!=NULL){
             temp=temp->right;
         }
         if(rightLL){
             
             temp->right=rightLL;
             A->right=leftLL;
             A->left=NULL;
         }else{
             A->right=leftLL;
             A->left=NULL;
         }
     }
     return A;
}
