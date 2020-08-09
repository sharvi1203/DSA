/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* A, int B) {
    queue<TreeNode*> q;
    vector<int> v;
    q.push(A);
    q.push(NULL);
    if(A->val==B){
        return v;
    }
      int flag=0;
    while(!q.empty()){

        TreeNode* temp=q.front();
          q.pop();
        if(temp==NULL){
              if(flag==1)
              break;
           q.push(NULL);
        }
      
          else{
            if((temp->left && temp->left->val ==B) || (temp->right && temp->right->val ==B)){
                flag=1;
                continue;
            }
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
  
      while(!q.empty()){
        TreeNode *temp = q.front();
        v.push_back(temp->val);
        q.pop();
    }
  return v;
}
//           1
//         2   3
//     4     5      6     7
// 8    9  10 11 12 13 14 15  


//
