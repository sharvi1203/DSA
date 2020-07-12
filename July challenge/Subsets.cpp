class Solution {
public:
    vector<vector<int>> subsetUtil(vector<int>& nums,int index){
        if(index==nums.size()){
            vector<vector<int>> ans;
            ans.push_back({});
            return ans;
        }
        vector<vector<int>> ans1=subsetUtil(nums,index+1);
        vector<vector<int>> ans;
        for(int i=0;i<ans1.size();i++){
            vector<int> temp;
            temp.push_back(nums[index]);
            for(int j=0;j<ans1[i].size();j++){
                temp.push_back(ans1[i][j]);
            }
            ans.push_back(temp);
        }
        for(int i=0;i<ans1.size();i++){
            ans.push_back(ans1[i]);
        }
        return ans;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        return subsetUtil(nums,0);
    }
};

#################################################################
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs;
        vector<int> sub;
        subsets(nums, 0, sub, subs);
        return subs;
    }
private:
    void subsets(vector<int>& nums, int i, vector<int>& sub, vector<vector<int>>& subs) {
        subs.push_back(sub);
        for (int j = i; j < nums.size(); j++) {
            sub.push_back(nums[j]);
            subsets(nums, j + 1, sub, subs);
            sub.pop_back();
        }
    }
};
