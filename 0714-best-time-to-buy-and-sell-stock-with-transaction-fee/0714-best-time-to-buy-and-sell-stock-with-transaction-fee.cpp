class Solution {
public:
    vector<vector<int>>dp;
    int profit(vector<int>& prices, int pos, bool bght, int f){
        if(pos>=prices.size()) return 0;
        if(dp[pos][bght]!=-1){
            return dp[pos][bght];
        }
        int a=profit(prices, pos+1, bght, f);
        if(bght){
            a=max(a, profit(prices, pos+1,!bght, f)+prices[pos]-f);
        }
        else{
            a=max(a, profit(prices, pos+1, !bght, f)-prices[pos]);
        }
        dp[pos][bght]=a;
        return a;
    }


    int maxProfit(vector<int>& prices, int fee) {
        dp.resize(prices.size(), vector<int>(2, -1));
        return profit(prices, 0, false, fee);
    }
};