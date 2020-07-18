vector <int> zigZagTraversal(Node* root)
{
    
	vector<int> v;
	if(root==NULL){
	    return v;
	}
	stack<Node*> s1,s2;
	s1.push(root);
	while(!s1.empty() || !s2.empty()){
	    while(!s1.empty()){
	        Node* temp=s1.top();
	        s1.pop();
	        v.push_back(temp->data);
	        if(temp->left)  s2.push(temp->left);
	        if(temp->right) s2.push(temp->right);
	    }
	    while(!s2.empty()){
	        Node* temp=s2.top();
	        s2.pop();
	        v.push_back(temp->data);
	        if(temp->right) s1.push(temp->right);
	        if(temp->left)  s1.push(temp->left);
	    }
	}
	return v;
}
