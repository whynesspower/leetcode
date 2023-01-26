class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>>dp(k+2, vector<int>(n, INT_MAX));
        for(int i=0;i<=k+1;i++){
            dp[i][src]=0;
        }
        for(int i=1;i<=(k+1); i++){
            for(auto &f:flights){
                if(dp[i-1][f[0]]!=INT_MAX){
                    dp[i][f[1]]=min(dp[i][f[1]], dp[i-1][f[0]]+f[2]);
                }    
            }
        }
        return dp[k+1][dst]==INT_MAX?-1:dp[k+1][dst];
    }
};