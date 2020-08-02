#include <bits/stdc++.h>
using namespace std;
class Node 
{ 
    public:
    int key; 
    Node* left, *right; 
}; 
Node* newNode(int key) 
{ 
    Node* temp = new Node; 
    temp->key = key; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
int findLeafDown(Node* root,int lev,int& minVal){
    if(root==NULL){
        return INT_MAX;
    }
    if(root->left==NULL && root->right==NULL){
        if(lev<minVal){
            minVal=lev;
        }
        return minVal;
    }
    int a = findLeafDown(root->left,lev+1,minVal);
    int b = findLeafDown(root->right,lev+1,minVal);
    return min(a,b);
}
int findThroughparent(Node* root,Node* x,int& minVal){
    if(root==NULL){
        return -1;
    }
    if(root==x){
        return 0;
    }
    int l=findThroughparent(root->left,x,minVal);
    if(l!=-1){
        return findLeafDown(x,l+2,minVal);
    }
    int r=findThroughparent(root->right,x,minVal);
    if(r!=-1){
        return findLeafDown(x,r+2,minVal);
    }
    return -1;
}
int minimumDistance(Node* root,Node* x){
    int minVal=INT_MAX;
    int a=findLeafDown(x,0,minVal);
    int b=findThroughparent(root,x,minVal);
    return min(a,b);
}
int main() {
	Node *root  = newNode(1); 
    root->left  = newNode(12); 
    root->right = newNode(13); 
  
    root->right->left   = newNode(14); 
    root->right->right  = newNode(15); 
  
    root->right->left->left   = newNode(21); 
    root->right->left->right  = newNode(22); 
    root->right->right->left  = newNode(23); 
    root->right->right->right = newNode(24); 
  
    root->right->left->left->left  = newNode(1); 
    root->right->left->left->right = newNode(2); 
    root->right->left->right->left  = newNode(3); 
    root->right->left->right->right = newNode(4); 
    root->right->right->left->left  = newNode(5); 
    root->right->right->left->right = newNode(6); 
    root->right->right->right->left = newNode(7); 
    root->right->right->right->right = newNode(8); 
  
    Node *x = root->right; 
  
    cout << "The closest leaf to the node with value "
         << x->key << " is at a distance of "
         << minimumDistance(root, x) << endl;
	return 0;
}
