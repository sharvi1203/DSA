class Solution {
public:
    long long findTargetSumWays(vector<int>& nums,int i,int S,long long sum,vector<vector<int>>& dp) {
        if(S==sum && i==nums.size()){
            if(sum<0){
                int x=(-sum)+1001;
                dp[i][x]=1;
                return 1;
            }
            dp[i][sum]=1;
            return 1;
        }
        if(i==nums.size()){
            return 0;
        }
        if(sum<0){
            int x=(-sum)+1001;
            if(dp[i][x]!=-1){
                return dp[i][x];
            }
        }else if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        
        long long ans1=findTargetSumWays(nums,i+1,S,sum-nums[i],dp);
        long long ans2=findTargetSumWays(nums,i+1,S,sum+nums[i],dp);
        if(sum<0){
            int x=(-sum)+1001;
            dp[i][x]=ans1+ans2;
            return dp[i][x];
        }
        dp[i][sum]=ans1+ans2;
        return ans1+ans2;
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum=0;
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(2002,-1));
        return findTargetSumWays(nums,0,S,0,dp);
    }
};
/*    


*/
