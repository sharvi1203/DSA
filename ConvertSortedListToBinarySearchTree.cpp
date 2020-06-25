##################################################################
//O(N)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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
    int length(ListNode* head){
        int l=0;
        while(head!=NULL){
            head=head->next;
            l++;
        }
        return l;
    }
    TreeNode* convertListToBST(int start,int end,ListNode** head){
        if(start>end){
            return NULL;
        }
        int mid=(start+end)/2;
        TreeNode* left=convertListToBST(start,mid-1,head);
        TreeNode* root=new TreeNode((*head)->val);
        root->left=left;
        *head=(*head)->next;
        root->right=convertListToBST(mid+1,end,head);
        return root;
            
    }
    TreeNode* sortedListToBST(ListNode* head) {
        int len=length(head);
        return convertListToBST(0,len-1,&head);
    }
};

##################################################################
//O(N)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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
    TreeNode* util(vector<int>& v,int start,int end){
        if(start>end){
            return NULL;
        }
        int mid=(start+end)/2;
        TreeNode* root=new TreeNode(v[mid]);
        root->left=util(v,start,mid-1);
        root->right=util(v,mid+1,end);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> v;
        while(head!=NULL){
            v.push_back(head->val);
            head=head->next;
        }
        return util(v,0,v.size()-1);
    }
};


##################################################################
//O(NlogN)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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
    ListNode* middleElement(ListNode* head){
        ListNode *slow=head,*fast=head,*prev=NULL;
        while(fast!=NULL && fast->next!=NULL){
            prev=slow;
            fast=fast->next->next;
            slow=slow->next;
        }
        if(prev!=NULL){
            prev->next=NULL;
        }
        return slow;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        ListNode* mid=middleElement(head);   
        TreeNode* root=new TreeNode(mid->val);
        if(head==mid){
            return root;
        }
        root->left=sortedListToBST(head);
        root->right=sortedListToBST(mid->next);
        return root;
    }
};

/* Why O(NLogN) ? 
https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/solution/
*/
