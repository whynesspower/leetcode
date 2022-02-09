class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int ans=0;
        
        for(int x:nums){
            mp[x]++;
        }
        
        for(auto it:mp){
            if((k==0 and it.second>1) or (k>0 and mp.count(it.first+k))){
                ans++;
            }
        }
        
        return ans;
        
    }
};