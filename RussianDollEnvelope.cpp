/*
  You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.

  What is the maximum number of envelopes can you Russian doll? (put one inside other)

  Note:
  Rotation is not allowed.

  Example:

  Input: [[5,4],[6,4],[6,7],[2,3]]
  Output: 3 
  Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
  
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
