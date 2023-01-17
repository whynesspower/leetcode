class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n=nums.size();
        int pairs=0;
        int l=0;
        long long ans=0;
        for(int i=0;i<n;i++){
            pairs+=mp[nums[i]];
            mp[nums[i]]++;
            if(pairs>=k){
                while(l<=i and pairs>=k){
                    ans+=(nums.size()-i);
                    mp[nums[l]]--;
                    pairs-=mp[nums[l]];
                    if(mp[nums[l]]==0) mp.erase(nums[l]);
                    l++;
                }
            }
        }
        return ans;
    }
};