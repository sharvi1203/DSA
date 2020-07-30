vector <int> bfs(vector<int> g[], int N) {
    vector<int> v;
    queue<int> q;
    vector<int> visited(N,false);
    q.push(0);
    while(!q.empty()){
        int front=q.front();
        v.push_back(front);
        q.pop();
        for(auto i=g[front].begin();i<g[front].end();i++){
            if(!visited[*i]){
                q.push(*i);
                visited[*i]=true;
            }
        }
    }
    return v;
    
}
