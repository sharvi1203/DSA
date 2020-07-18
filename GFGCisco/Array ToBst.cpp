#include<iostream>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
};
TreeNode* new_node(int val){
    TreeNode* root=new TreeNode();
    root->val=val;
    root->left=NULL;
    root->right=NULL;
    return root;
}
TreeNode* construct(int arr[],int left,int right){
    if(left>right){
        return NULL;
    }
    int  mid=(left+right)/2;
    TreeNode* root=new_node(arr[mid]);
    root->left=construct(arr,left,mid-1);
    root->right=construct(arr,mid+1,right);
    return root;
}
void preorder(TreeNode* root){
    if(root==NULL){
        return;
    }
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    TreeNode* root=construct(arr,0,n-1);
	    preorder(root);
	    cout<<endl;
	}
	return 0;
}
