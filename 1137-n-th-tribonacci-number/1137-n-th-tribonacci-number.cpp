class Solution {
public:
    int dfs(int n, vector<int>&dp){
        // if(n<=0) return 0;
        if(dp[n]!=-1) return dp[n];
        if(n==0) {dp[n]=0;return dp[n];}
        if(n==1 or n==2){
            dp[n]=1;
            return dp[n];
        }
        dp[n]=dfs(n-1, dp)+dfs(n-2, dp)+dfs(n-3, dp);
        return dp[n];
    }
    
    
    int tribonacci(int n) {
        vector<int>dp(n+3, -1);
        dfs(n, dp);
        return dp[n];
    }
};