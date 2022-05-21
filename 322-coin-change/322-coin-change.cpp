class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int max = amount+1;
        vector<int> dp(amount+1, max);
        dp[0]=0;
        
        for(int i=1;i<=amount;i++){
            for(auto &c:coins){
                if(i-c>=0){
                dp[i]=min(dp[i], dp[i-c]+1);
                }
            }
        }
        return (dp[amount]>amount)?-1:dp[amount];
    }
};