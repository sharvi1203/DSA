class Solution {
public:
    int util(string& s1,string& s2,int i,int j,vector<vector<int>>& dp){
        if(i==s1.size() && j==s2.size()){
            dp[i][j]=0;
            return 0;
        }
        if(i==s1.size() || j==s2.size()){
            int x=0;
            while(i<s1.size()){
                x+=int(s1[i]);
                i++;
            }
            while(j<s2.size()){
                x+=int(s2[j]);
                j++;
            }
            dp[i][j]=x;
            return x;
        }  
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans;
        if(s1[i]==s2[j]){
            ans=util(s1,s2,i+1,j+1,dp);
        }else{
            ans=min(s1[i]+util(s1,s2,i+1,j,dp),s2[j]+util(s1,s2,i,j+1,dp));
        }
        dp[i][j]=ans;
        return dp[i][j];
    }
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return util(s1,s2,0,0,dp);
    }
};
/*
                                        sea eat         e+s+e+t
                                 ea eat             sea at   
                            a at                   ea at   sea t
                       '' t                      a at  ea t
                     '' ''                     ''t
                     
        ''  

        
*/
