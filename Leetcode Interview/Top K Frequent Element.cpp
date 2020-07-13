class Solution {
public:
    static bool compare(pair<int,int>& a,pair<int,int> &b){
        if(a.second==b.second){
            return a.first>b.first;
        }
        return a.second>b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        vector<int> ans;
        if(k>nums.size()){
            return ans;
        }
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
        }
        vector<pair<int,int>> v(map.begin(),map.end());
        sort(v.begin(),v.end(),compare);
        for(int i=0;i<v.size();i++){
            cout<<v[i].first<<" "<<v[i].second<<endl;
        }
        for(int i=0;i<k;i++){
            ans.push_back(v[i].first);
        }
        return ans;
    }
};
