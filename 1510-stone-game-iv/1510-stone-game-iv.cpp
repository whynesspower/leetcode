class Solution {
public:
    bool winnerSquareGame(int n) {
        bool dp[n+1];
        memset(dp, false, sizeof(dp));
        for(int i=1;i<=n;i++){
            for(int j=1;j*j<=i;j++){
                if(dp[i-j*j]==false){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[n];
    }
};