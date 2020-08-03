//Use of new class for horizontal distance
class NodeWithHd{
  public:
  Node* root;
  int hd;
  NodeWithHd(Node* temp){
      root=temp;
      hd=0;
  }
};
vector<int> bottomUtil(NodeWithHd* root){
      int minHd=INT_MAX,maxHd=INT_MIN;
      unordered_map<int,vector<int>> map;
      vector<int> ans;
      queue<NodeWithHd*> q;
      q.push(root);
      root->hd=0;
      map[0].push_back(root->root->data);
      while(!q.empty()){
          NodeWithHd* front=q.front();
          int hd=front->hd;
          minHd=min(minHd,hd);
          maxHd=max(maxHd,hd);
          q.pop();
          if(front->root->left){
              NodeWithHd* left=new NodeWithHd(front->root->left);
              q.push(left);
              left->hd=hd-1;
              map[hd-1].push_back(left->root->data);
          }
          if(front->root->right){ 
              NodeWithHd* right=new NodeWithHd(front->root->right);
              q.push(right);
              right->hd=hd+1;
              map[hd+1].push_back(right->root->data);
          }
      }
      
      for(int i=minHd;i<=maxHd;i++){
          vector<int> temp=map[i];
          ans.push_back(temp[temp.size()-1]);
      }
   return ans;
}
vector <int> bottomView(Node *root)
{
   NodeWithHd* temp=new NodeWithHd(root);
   return bottomUtil(temp);
   
}
