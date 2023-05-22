class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto x: nums){
            mp[x]++;
        }
        map<int,vector<int>, greater<int>>mp2;
        for(auto x:mp){
            mp2[x.second].push_back(x.first);
        }
        vector<int>ans;
        for(auto x:mp2){
            if( ans.size()>=k) break;
            for(auto y:x.second){
                if(ans.size()>=k) break;
                ans.push_back(y);
            }
        }
        return ans;
    }
};