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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL){
            vector<vector<int>> v;
            return v;
        }
        vector<vector<int>> ans;
        vector<int> v={};
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* front=q.front();
            q.pop();
            if(front){
                v.push_back(front->val);
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
            }else{
                ans.push_back(v);
                v.clear();
                if(q.size()>0){
                    q.push(NULL);
                }
            }
        }
        return ans;
    }
};
