class Solution {
public:
    bool DFSUtil(int numCourses,int sv,vector<vector<int>>& adj,vector<int>& visited){
        if(visited[sv]==2){
            return true;
        }
        if(visited[sv]==1){
            return false;
        }
        visited[sv]=1;
        bool flag=true;
        for(auto i=adj[sv].begin();i<adj[sv].end();i++){
            if(visited[*i]!=2){
                 flag=DFSUtil(numCourses,*i,adj,visited);
                 if(!flag){
                     return flag;
                 }
            }
        }
        visited[sv]=2;
        return flag; 
    }
    bool DFS(int numCourses,vector<vector<int>>& adj){
        vector<int> visited(numCourses,0); // 0 1
        bool flag=true;
        for(int i=0;i<numCourses;i++){
            if(visited[i]==0){
                flag=DFSUtil(numCourses,i,adj,visited);
                if(!flag){
                    return flag;
                }
            }
        }
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        int size=prerequisites.size();
        for(int i=0;i<size;i++){
            vector<int> temp=prerequisites[i];
            adj[temp[1]].push_back(temp[0]);
        }
        return DFS(numCourses,adj);   
    }
};
