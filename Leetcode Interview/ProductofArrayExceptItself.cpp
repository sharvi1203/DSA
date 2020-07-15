/*
Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.

Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)
*/

#### using extra space (inefficient)######## 
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       int n=nums.size();
       vector<int> left(n,1);
       vector<int> right(n,1);
       vector<int>  ans(n,1);
        for(int i=1;i<n;i++){
            left[i]=left[i-1]*nums[i-1];
        }
        for(int i=n-2;i>=0;i--){
            right[i]=right[i+1]*nums[i+1];
        }
        for(int i=0;i<n;i++){
            ans[i]=left[i]*right[i];
        }
        return ans;
    }
};
#######################################################################
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int temp=1;
        vector<int> ans(n,1);
        for(int i=0;i<n;i++){
            ans[i]=temp;
            temp*=nums[i];
        }
        temp=1;
        for(int i=n-1;i>=0;i--){
            ans[i]*=temp;
            temp*=nums[i];
        }
        return ans;
    }
};
