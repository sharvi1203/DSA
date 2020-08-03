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
    class NodeWithHd{
        public:
            TreeNode* root;
            int hd;
            int height;
            NodeWithHd(TreeNode* temp){
                root=temp;
                hd=0;
                height=0;
            }
    };
    static bool myCompare(NodeWithHd* a,NodeWithHd* b){
        return (a->height<b->height ||(a->height==b->height && (a->root->val<b->root->val)));
    }
    vector<vector<int>> verticalTraversalUtil(NodeWithHd* root){
        int minHd=INT_MAX,maxHd=INT_MIN;  
        vector<vector<int>> ans;
        unordered_map<int,vector<NodeWithHd*>> map;
        queue<NodeWithHd*> q;
        q.push(root);
        map[0].push_back(root);
        while(!q.empty()){//O(n)
            NodeWithHd* front=q.front(); //O(1)
            int hd=front->hd;
            int height=front->height;
            minHd=min(minHd,hd);
            maxHd=max(maxHd,hd);//O(1)
            q.pop();//O(1)
            if(front->root->left){
                NodeWithHd* left=new NodeWithHd(front->root->left); //O(1)
                q.push(left);
                left->hd=hd-1;
                left->height=height+1;
                map[hd-1].push_back(left);//O(1)
            }
            if(front->root->right){
                NodeWithHd* right=new NodeWithHd(front->root->right);
                q.push(right);
                right->hd=hd+1;
                right->height=height+1;
                map[hd+1].push_back(right);
            }
        }
        for(int i=minHd;i<=maxHd;i++){
            vector<NodeWithHd*> temp=map[i];
            sort(temp.begin(),temp.end(),myCompare); //O(nlogn)
            vector<int> temp1;
            for(int j=0;j<temp.size();j++){        //O(n)     
                temp1.push_back(temp[j]->root->val);           
            }
            ans.push_back(temp1); //O(1)
        }//O((maxhd-minhd)*nlogn)
        
        return ans;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
         NodeWithHd* temp=new NodeWithHd(root);
         return verticalTraversalUtil(temp);
    }
};







        5     //Case for max size of vector
    4 
        6
    3
        9   
