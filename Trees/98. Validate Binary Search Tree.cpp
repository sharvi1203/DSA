/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root,TreeNode* maxNode,TreeNode* minNode){
        if(!root){
            return true;
        }
        int val=root->val;
        if(minNode!=NULL && val<=minNode->val)  return false;
        if(maxNode!=NULL && val>=maxNode->val)  return false;
        
        if(! isValidBST(root->right,maxNode,root))  return false;
        if(! isValidBST(root->left,root,minNode))   return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
       return isValidBST(root,NULL,NULL);
    }
};
