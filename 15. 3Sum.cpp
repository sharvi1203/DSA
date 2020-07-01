class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.empty()){
            return res;
        }
        int size=nums.size();
        sort(nums.begin(),nums.end());
        int right=nums.size()-1,left=0;
        for(int i=0;i<size;i++){
            if(nums[i]>0)   break;
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            left=i+1;   right=size-1;
            while(left<right){
                int sum=nums[i]+nums[left]+nums[right];
                if(sum<0){
                    left++;
                }else if(sum>0){
                    right--;
                }else{
                    res.push_back({nums[i],nums[left],nums[right]});
                    int last_left=nums[left],last_right=nums[right];
                    while(left<right && last_left==nums[left])  left++;
                    while(left<right && last_right==nums[right])    right--;
                }
            }
        }
        return res;
    }
};
