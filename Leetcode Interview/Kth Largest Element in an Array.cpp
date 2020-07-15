/*
1. Directly sort
2. Using priority queue(Max Heap)
3. Using quick Sort partition method(Below Implementation)
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       int size=nums.size();
       int left=0,right=size-1,kth;
       while(true){
           int index=partition(nums,left,right);
           if(index==k-1){
               kth=nums[index];
               break;
           }
           if(index>k-1){
               right=index-1;
           }else{
               left=index+1;
           }
       } 
        return kth;
    }
    int partition(vector<int>& nums,int left,int right){
        int pivot=nums[left],l=left+1,r=right;
        while(l<=r){
            if(nums[l]<pivot && nums[r]>pivot){
                swap(nums[l++],nums[r--]);
            }
            if(nums[l]>=pivot){
                l++;
            }
            if(nums[r]<=pivot){
                r--;
            }
        }
        swap(nums[left],nums[r]);
        return r;
    }
};
