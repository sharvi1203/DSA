/*
  Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:

  Si % Sj = 0 or Sj % Si = 0.

  If there are multiple solutions, return any subset is fine.

  Example 1:

  Input: [1,2,3]
  Output: [1,2] (of course, [1,3] will also be ok)
  Example 2:

  Input: [1,2,4,8]
  Output: [1,2,4,8]
*/
 class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            vector<int> temp;
            return temp;
        }
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1);
        vector<int> prev(n,-1);
        int index=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(dp[i]<dp[j]+1){
                        dp[i]=dp[j]+1;
                        prev[i]=j;
                    }
                }
            }
            if(dp[index]<dp[i]){
                index=i;
            }
        }
        vector<int> ans;
        while(index>=0){
            ans.push_back(nums[index]);
            index=prev[index];
        }
        return ans;
    }
};
