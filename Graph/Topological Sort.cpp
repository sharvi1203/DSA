void topoSortUtil(int V,int sv,vector<int> adj[],stack<int>& s,vector<bool>& visited){
    visited[sv]=true;
    for(auto i=adj[sv].begin();i<adj[sv].end();i++){
        if(visited[*i]){
            continue;
        }
        topoSortUtil(V,*i,adj,s,visited);
    }
    s.push(sv);
}
vector<int> topoSort(int V, vector<int> adj[]) {
    stack<int> s;
    vector<bool> visited(V,false);
    vector<int> ans;
    for(int i=0;i<V;i++){
        if(!visited[i]){
            topoSortUtil(V,i,adj,s,visited);
        }
    }
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}
