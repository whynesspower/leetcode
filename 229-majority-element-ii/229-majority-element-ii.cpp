class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int ,int> mp;
        for(auto x:nums){
            mp[x]++;
        }
        vector<int> ans;
        int n=nums.size();
        for(auto it:mp){
            if(it.second> n/3){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};