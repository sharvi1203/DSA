bool isCyclicUtil(vector<int> g[], int V,int sv,int parent,vector<bool>& visited){
    visited[sv]=true;
    for(auto i=g[sv].begin();i<g[sv].end();i++){
        if(!visited[*i]){
            if(isCyclicUtil(g,V,*i,sv,visited)){
                return true;
            }
        }else if(*i!=parent){
            return true;
        }    
    }
    return false;
}
bool isCyclic(vector<int> g[], int V)
{
   vector<bool> visited(V,false);
   for(int i=0;i<V;i++){
       if(!visited[i]){
           if(isCyclicUtil(g,V,i,-1,visited)){
               return true;
           }
       }
   }
   return false;
}
