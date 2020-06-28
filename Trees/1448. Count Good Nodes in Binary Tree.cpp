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
    int goodNodes(TreeNode* root,int currMax){
        if(root==NULL){
            return 0;
        }
        int left=goodNodes(root->left,max(currMax,root->val));
        int right=goodNodes(root->right,max(currMax,root->val));
        int ans=0;
        if(root->val>=currMax){
            ans=1;
        }
        return left+right+ans;
       
    }
    int goodNodes(TreeNode* root) {
        return goodNodes(root,root->val);
    }
};
