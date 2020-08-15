class Solution {
public:
    double solve(int i,int j,int N,int K,vector<vector<vector<double>>>& v){
        if(i>=N || i<0 || j>=N || j<0){
            return 0;
        }
        if(K==0){
            v[i][j][K]=1;
            return 1;
        }
        if(v[i][j][K]!=-1){
            return v[i][j][K];
        }
       
        double x =solve(i+2,j+1,N,K-1,v)+solve(i+2,j-1,N,K-1,v)+solve(i-2,j+1,N,K-1,v)+solve(i-2,j-1,N,K-1,v)+solve(i+1,j+2,N,K-1,v)+solve(i+1,j-2,N,K-1,v)+solve(i-1,j+2,N,K-1,v)+solve(i-1,j-2,N,K-1,v);
      
        double ans=x/8;
        v[i][j][K]=ans;
        return v[i][j][K];

    }
    
    
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<vector<double>>> v(N+1,vector<vector<double>>(N+1,vector<double>(K+1,-1)));
        double x = solve(r,c,N,K,v); 
        return x;
    }
};
