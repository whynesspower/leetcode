class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        if(piles.size()==0) return 0;
        if(piles.size()==1) return piles[0];
        vector<vector<int>>dp(piles.size(), vector<int>(piles.size()+1,0));
        vector<int>sum(piles.size(), 0);
        sum[piles.size()-1]= piles[piles.size()-1];
        for(int i=piles.size()-2;i>=0;i--){
            sum[i]=sum[i+1]+piles[i];
        }
        helper(piles, dp, sum, 0, 1);
        return dp[0][1];
    }
    int helper(vector<int>& piles, vector<vector<int>>&dp, vector<int>&sum, int i, int M){
        
        if(i==piles.size()) return 0;
        if(2*M>=piles.size()-i) return sum[i];
        if(dp[i][M]) return dp[i][M];
        int mini=INT_MAX;
        for(int j=1;j<=2*M; j++){
            mini=min(mini, helper(piles, dp, sum, i+j, max(j, M)));
        }
        return dp[i][M]=sum[i]-mini;
    }
};