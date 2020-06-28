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
 
 //using Stack
class BSTIterator {
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        find_left(root);
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* top=st.top();
        st.pop();
        if(top->right!=NULL){
            find_left(top->right);
        }
        return top->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(st.empty()){
            return false;
        }else{
            return true;
        }
    }
    
    void find_left(TreeNode* root){
        TreeNode* p=root;
        while(p!=NULL){
            st.push(p);
            p=p->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
 
 ######################################################################
 //using inorder 
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
class BSTIterator {
public:
    TreeNode* root;
    int index;
    vector<int> v;
    BSTIterator(TreeNode* root) {
        this->root=root;
        index=-1;
        inorder(root);
    }
    
    /** @return the next smallest number */
    void inorder(TreeNode* node){
        if(node!=NULL){
            inorder(node->left);
            v.push_back(node->val);
            inorder(node->right);
        }
    }
    int next() {
        return v[++index];
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
       return index+1<v.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
