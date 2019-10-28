#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
    Node *left,*right;
    Node(int data){
    	this->data=data;
    	this->left=nullptr;
		this->right=nullptr;
	}
};
void printVertical(Node* node,int dist,auto &map){
	if(node==nullptr)
		return;
	map.insert(make_pair(dist,node->data));
	printVertical(node->left,dist-1,map);
	printVertical(node->right,dist+1,map);
}
void printVertical(Node *root){
	multimap<int,int> map;
	printVertical(root,0,map);
	int temp=0;
	for(auto it=map.begin();it!=map.end();it++){
		if(temp!=it->first){
		   cout<<endl;
		   temp=it->first;
		}
		cout<<it->second<<" ";
	}
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);
    root->right->left->right->left = new Node(9);
    root->right->left->right->right = new Node(10);
 
    printVertical(root);	
}
