class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int ans;
        int n=10001;
        int dp[10001];
        int sum[10001];
        memset(dp, 0, sizeof dp);
        memset(sum, 0, sizeof sum);
        
        for(int i=0;i<nums.size();i++){
            sum[nums[i]]+=nums[i];
        }
        dp[0]=0;
        dp[1]=sum[1];
        
        for(int i=2;i<n;i++){
            dp[i]=max(dp[i-2] + sum[i], dp[i-1]);
        }
        
        ans=dp[n-1];
        return ans;
    }
};