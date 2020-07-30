void dfsUtil(vector<int> g[], int N,int sv,vector<bool>& visited,vector<int>& v){
    v.push_back(sv);
    visited[sv]=true;
    for(auto i=g[sv].begin();i<g[sv].end();i++){
        if(!visited[*i]){
            dfsUtil(g,N,*i,visited,v);
        }
    }
}
vector <int> dfs(vector<int> g[], int N)
{
    vector<bool> visited(N,false);
    vector<int> v;
    dfsUtil(g,N,0,visited,v);
    return v;
}
