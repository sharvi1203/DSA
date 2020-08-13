#define mod 100000007
class Solution {
public:
    bool isValid(int m,int n,int i,int j){
        return i>=0 && i<m && j>=0 && j<n;
    }
    long long findPathsUtil(int m, int n, int N, int i, int j, vector<vector<vector<long long>>>& dp) {
        if(N!=0 && !isValid(m,n,i,j)){
            return 0;
        }
        if(N==0 && !isValid(m,n,i,j)){
            return 1;
        }
        if(N==0){
            return 0;
        }
        if(dp[i][j][N]!=-1){
            return dp[i][j][N]%mod;
        }
        long long ans1,ans2,ans3,ans4;
        ans1=ans2=ans3=ans4=0;
        ans1=findPathsUtil(m,n,N-1,i+1,j,dp)%mod;//1
        ans2=findPathsUtil(m,n,N-1,i,j+1,dp)%mod;//0
        ans3=findPathsUtil(m,n,N-1,i,j-1,dp)%mod;//1
        ans4=findPathsUtil(m,n,N-1,i-1,j,dp)%mod;//0
        dp[i][j][N]=((((ans1 %mod ) + ans2%mod)%mod+ ans3%mod)%mod + ans4%mod)%mod;
        
        return dp[i][j][N];
               
    }
    int findPaths(int m, int n, int N, int i, int j) {
        long long ans=0;
        vector<vector<vector<long long>>> dp(m+1,vector<vector<long long>>(n+1,vector<long long>(N+1,-1)));
        for(int k=1;k<=N;k++){
            ans=(ans%mod+findPathsUtil(m,n,k,i,j,dp)%mod)%mod;
        }
        return ans%mod;
    }
};

/*
    (i,j,N)
*/

