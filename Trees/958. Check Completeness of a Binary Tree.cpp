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
 //dfs approach
class Solution {
public:
    int count(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return count(root->left)+count(root->right)+1;
    }
    bool isComplete(TreeNode* root,int index,int total){
        if(root==NULL){
            return true;
        }
        if(index>total){
            return false;
        }
        return isComplete(root->left,2*index,total)&&isComplete(root->right,2*index+1,total);
    }
    bool isCompleteTree(TreeNode* root) {
        int total=count(root);
        return isComplete(root,1,total);
    }
};

//bfs approach
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool seenNull=false;
        while(!q.empty()){
            TreeNode* front=q.front();
            q.pop();
            if(front==NULL){
                seenNull=true;
            }else{
                if(seenNull)    return false;
                q.push(front->left);
                q.push(front->right);
            }
        }
        return true;
    }
};
