class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        
        unordered_map<int,int>dp;
        
        int ans=1;
        
        for(int i=0;i<arr.size();i++){
            ans=max( dp[arr[i]]=dp[arr[i]-diff]+1 ,ans );
        }
        
        return ans;
    }
};