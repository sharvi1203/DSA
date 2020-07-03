/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
*/
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        q.push(root);
        q.push(NULL);
        vector<int> v;
        while(q.size()>1){
            TreeNode* front=q.front();
            q.pop();
            if(front!=NULL){
                v.push_back(front->val);
                if(front->left) q.push(front->left);
                if(front->right)    q.push(front->right);
            }else{
                ans.push_back(v);
                v.clear();
                q.push(NULL);
            }
        }
        ans.push_back(v);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
