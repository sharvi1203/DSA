struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

//You are required to complete this method
vector<int> levelOrder(Node* node)
{
  vector<int> v;
  queue<Node*> q;
  q.push(node);
  while(!q.empty()){
      Node* front=q.front();
      q.pop();
      v.push_back(front->data);
      if(front->left)   q.push(front->left);
      if(front->right)  q.push(front->right);
  }
  return v;
}
