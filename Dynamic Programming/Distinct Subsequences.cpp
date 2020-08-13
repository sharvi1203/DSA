class Solution {
public:
    int numDistinct(string s,string t,int i,int j,vector<vector<int>>& dp){
        if(i==s.size() && j==t.size()){
            dp[i][j]=1;
            return 1;
        }
        if(s.size()-i<t.size()-j){
            dp[i][j]=0;
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==t[j]){
            int ans1=numDistinct(s,t,i+1,j+1,dp);
            int ans2=numDistinct(s,t,i+1,j,dp);
            dp[i][j]=ans1+ans2;
        }else{
            int ans3=numDistinct(s,t,i+1,j,dp);
            dp[i][j]=ans3;
        }
        return dp[i][j];
    }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return numDistinct(s,t,0,0,dp);
    }
};

/*                           (0,0)
                        rabbbit rabbit
            (1,1)                                         (1,0)
        abbbit  abbit                                abbbit rabbit   
        (2,2)                      (2,1)                
    bbbit  bbit                 bbbit  abbit         bbbit rabbit                      
    (3,4)     (3,2) 
bbit   bit  bbit bbit(1)       bbit abbit(0)         0
bit it   bit bit(1)
it it(1)
    

*/
