class Solution {
public:
    bool isValid(int i,int j,int n,int m,vector<vector<int>> grid){
        return i>=0 && j>=0 && i<n && j<m && grid[i][j]==1;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push(make_pair(i,j));     //O(n*m)
                }
            }
        }
        int count=0;
        q.push(make_pair(-1,-1));
        while(!q.empty()){      //O(n*m)
            pair<int,int> front=q.front(); // O(1)
            int i=front.first;
            int j=front.second;
            q.pop();
            if(front.first== -1 && front.second== -1){
                if(q.size()==0){
                    break;
                }
                count++;
                q.push(front);
            }else{
                if(isValid(i+1,j,n,m,grid)){
                    grid[i+1][j]=2;
                    q.push(make_pair(i+1,j));
                }
                if(isValid(i-1,j,n,m,grid)){
                    grid[i-1][j]=2;
                    q.push(make_pair(i-1,j));
                }
                if(isValid(i,j+1,n,m,grid)){
                    grid[i][j+1]=2;
                    q.push(make_pair(i,j+1));
                }
                if(isValid(i,j-1,n,m,grid)){
                    grid[i][j-1]=2;
                    q.push(make_pair(i,j-1));
                }
            }
        }
         for(int i=0;i<n;i++){          //O(n*m)
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                   return -1;
                }
            }
        }
        
        //3*O(n*m)
        return count;
    }
};
