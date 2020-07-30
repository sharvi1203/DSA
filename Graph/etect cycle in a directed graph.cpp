bool isCyclicUtil(int sv,int V,vector<int> adj[],vector<bool>& visited,vector<bool>& recStack){
    visited[sv]=true;
    recStack[sv]=true;
    for(auto i=adj[sv].begin();i<adj[sv].end();i++){
        if(!visited[*i] && isCyclicUtil(*i,V,adj,visited,recStack)){
            return true;
        }else if(recStack[*i]){
            return true;
        }
    }
    recStack[sv]=false;
    return false;
}
bool isCyclic(int V, vector<int> adj[])
{
    vector<bool> visited(V,false);
    vector<bool> recStack(V,false);
    for(int i=0;i<V;i++){
       if(!visited[i]){
           if(isCyclicUtil(i,V,adj,visited,recStack)){
               return true;
           }
       }
    }
    return false;
}
