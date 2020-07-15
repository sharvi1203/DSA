class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> map;
        for(int i=0;i<strs.size();i++){
            string s=strs[i];
            sort(s.begin(),s.end());
            map[s].push_back(strs[i]);
        }
        for(auto m :map){
            ans.push_back(m.second);
        }
        return ans;
    }
};
