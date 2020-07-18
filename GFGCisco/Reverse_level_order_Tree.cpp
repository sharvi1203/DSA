void reversePrint(Node *root)
{
    stack<int> s;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* front=q.front();
        q.pop();
        s.push(front->data);
        if(front->right) q.push(front->right);
        if(front->left) q.push(front->left);
    }
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}
