void connect(Node *p)
{
   queue<Node*> q;
   q.push(p);
   q.push(NULL);
   while(!q.empty()){
       Node* front=q.front();
       q.pop();
       if(front!=NULL){
           front->nextRight=q.front();
           if(front->left)  q.push(front->left);
           if(front->right) q.push(front->right);
       }else{
           if(q.size()==0){
               break;
           }
           q.push(NULL);
       }
   }
}
