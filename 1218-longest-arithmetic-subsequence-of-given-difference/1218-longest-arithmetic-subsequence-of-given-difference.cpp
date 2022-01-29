class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        unordered_map<int,int>dp;
        int ans=1;
        
        for(auto x:arr){
            ans=max(dp[x]=dp[x-diff]+1, ans);
        }
        
        return ans;
    }
};