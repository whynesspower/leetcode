class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        dp[n-1]=0;
        for(int i=n-2;i>=0;i--){
            int m=nums[i];
            if(m==0){
                dp[i]=-1;
                continue;
            }
            int currmax=5752;
            for(int j=1;j<=m;j++){
                if(i+j<n){
                    if(dp[i+j]!=-1)
                        currmax=min(currmax, dp[i+j]);
                }
                else break;
            }
//             if(currmax==INT_MAX){
                
//             }
            dp[i]=currmax+1;
        }
        return dp[0];
    }
};