/*
  You are given n pairs of numbers. In every pair, the first number is always smaller than the second number.

  Now, we define a pair (c, d) can follow another pair (a, b) if and only if b < c. Chain of pairs can be formed in this fashion.

  Given a set of pairs, find the length longest chain which can be formed. You needn't use up all the given pairs. You can select pairs in any order.

  Example 1:
  Input: [[1,2], [2,3], [3,4]]
  Output: 2
  Explanation: The longest chain is [1,2] -> [3,4]
  Note:
  The number of given pairs will be in the range [1, 1000].
  
*/
bool myCompare(vector<int>& a,vector<int>& b){
    if(a[0]<b[0]){
       return true; 
    }
    else if(b[1]<b[1] && a[0]==b[0]){
        return true;
    }
    return false;
}
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();
        if(n==0){
            return 0;
        }
        sort(envelopes.begin(),envelopes.end(),myCompare);
        vector<int> dp(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(envelopes[i][0]>envelopes[j][0] && envelopes[i][1]>envelopes[j][1] && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                }
            }
        }
        int ans=dp[0];
        for(int i=1;i<n;i++){
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};
