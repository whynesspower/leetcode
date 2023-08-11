class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int ans=0;
        vector<int>dp(amount+1, 0);
        dp[0]=1;
        for(int j=0;j<coins.size();j++){
            for(int i=1;i<=amount;i++){
                int currAmount= coins[j];
                if(i-currAmount>=0){
                    dp[i]+=dp[i-currAmount];
                }
            }
        }

        return dp[amount];
    }
};
// amount = 3
// ways= [1,2] [1,1,1], []