/*
  Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

  Example 1:

  Input: n = 12
  Output: 3 
  Explanation: 12 = 4 + 4 + 4.
  Example 2:

  Input: n = 13
  Output: 2
  Explanation: 13 = 4 + 9.
*/
class Solution {
public:
    int numSquares(int n) {
        int val=floor(sqrt(n));
        vector<int> ans;
        for(int i=1;i<=val;i++){
            //cout<<i*i<<" ";
            ans.push_back(i*i);
        }
        vector<int> dp(n+1,n+1);
        dp[0]=0;
        for(int i=0;i<ans.size();i++){
            for(int j=ans[i];j<=n;j++){
                dp[j]=min(dp[j-ans[i]]+1,dp[j]);
            }
        }
        return dp[n];
        //return val;
    }
};
