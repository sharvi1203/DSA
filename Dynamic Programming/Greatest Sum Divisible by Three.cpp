/*
Given an array nums of integers, we need to find the maximum possible sum of elements of the array such that it is divisible by three.

 

Example 1:

Input: nums = [3,6,5,1,8]
Output: 18
Explanation: Pick numbers 3, 6, 1 and 8 their sum is 18 (maximum sum divisible by 3).
Example 2:

Input: nums = [4]
Output: 0
Explanation: Since 4 is not divisible by 3, do not pick any number.
Example 3:

Input: nums = [1,2,3,4,4]
Output: 12
Explanation: Pick numbers 1, 3, 4 and 4 their sum is 12 (maximum sum divisible by 3).
 

Constraints:

1 <= nums.length <= 4 * 10^4
1 <= nums[i] <= 10^4
*/
/*
A = [3,6,5,1,8]
buckets { 0, 0, 0 }
          0  1  2
A = [3,6,5,1,8]
     ^
buckets { 3, 0, 0 }
          0  1  2
A = [3,6,5,1,8]
       ^
buckets { 9, 0, 0 }
          0  1  2
A = [3,6,5,1,8]
         ^
buckets { 9, 0, 14 }
          0  1   2
A = [3,6,5,1,8]
           ^
buckets { 15, 10, 14 }
           0   1   2
A = [3,6,5,1,8]
             ^
buckets { 18, 22, 23 }
           0   1   2
           
the answer in buckets[0] is 18
Example 2:
A = [4]
buckets { 0, 0, 0 }
          0  1  2
A = [4]
     ^
buckets { 0, 4, 0 }
          0  1  2
          
the answer in buckets[0] is 0
Example 3:
A = [1,2,3,4,4]
buckets { 0, 0, 0 }
          0  1  2
          
A = [1,2,3,4,4]
     ^
buckets { 0, 1, 0 } 
          0  1  2
A = [1,2,3,4,4]
       ^
buckets { 3, 1, 2 } 
          0  1  2
          
A = [1,2,3,4,4]
         ^
buckets { 6, 4, 5 } 
          0  1  2
A = [1,2,3,4,4]
           ^
buckets { 9, 10, 8 }
          0   1  2
A = [1,2,3,4,4]
             ^
buckets { 12, 13, 14 } 
           0   1   2
the answer in buckets[0] is 12

*/
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp(3,0),dp1;
        int size=nums.size();
        for(int i=0;i<size;i++){
            dp1=dp;
            for(int j=0;j<3;j++){
                dp[(nums[i]+dp1[j])%3]=max( dp[(nums[i]+dp1[j])%3], nums[i]+dp1[j]);
            }
        }
        return dp[0];
    }
};
