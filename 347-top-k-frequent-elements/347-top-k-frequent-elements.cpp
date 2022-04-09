class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int,int>>v;
        unordered_map<int, int>mp;
        
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;    
        }
        for(auto it:mp){
            v.push_back(make_pair(it.second, it.first));
        }
        vector<int> ans;
        sort(v.begin(), v.end(), greater<pair<int,int>>());
        for(int i=0;i<k;i++){
            ans.push_back(v[i].second);
        }
        return ans;
    }
};


