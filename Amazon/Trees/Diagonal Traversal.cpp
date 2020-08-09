/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<int> Solution::solve(TreeNode* root) {
    queue<TreeNode*> q1;
    vector<int> v;
     if(root==NULL){
        return v;
    }
    TreeNode* temp=root;
    while(temp!=NULL){
        v.push_back(temp->val);
        if(temp->left!=NULL){
            q1.push(temp->left);
        }
        temp=temp->right;
    }
    while(!q1.empty()){
        temp=q1.front();
        q1.pop();
        while(temp!=NULL){
            v.push_back(temp->val);
            if(temp->left!=NULL){
                q1.push(temp->left);
            }
            temp=temp->right;
        }
    }
    return v;
}

    
          
          
    
          
          
          
          
          
          
          
