/*
   Given an array of integers nums and a positive integer k, find whether it's possible to divide this array into k non-empty subsets whose sums are all equal.



  Example 1:

  Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
  Output: True
  Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.


  Note:

  1 <= k <= len(nums) <= 16.
  0 < nums[i] < 10000.
  
*/
class Solution {
public:
    bool canPartition(int index,vector<int>& nums,vector<bool>& used,int k,int sumTillNow,int targetSum){
        if(k==1){
            return true;
        }
        if(sumTillNow==targetSum){
            return canPartition(0,nums,used,k-1,0,targetSum);
        }
        for(int i=index;i<nums.size();i++){
            if(!used[i]) { //&& sumTillNow + nums[i] <= targetSum){
                used[i]=true;
                if(canPartition(i+1,nums,used,k,sumTillNow+nums[i],targetSum)){
                    return true;    
                }
                used[i]=false;
            }
        }
        return false; 
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        vector<bool> used(nums.size(),false);
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(k==0 || sum%k!=0){
            return false;
        }
        return canPartition(0,nums,used,k,0,sum/k);
    }
};
