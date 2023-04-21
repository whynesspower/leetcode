#define ll long long
class Solution {
public:
    ll mod = 1e9+7;
    
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        vector<vector<int>> dp(minProfit+1, vector<int>(n+1, 0));
        dp[0][0]=1;
        // dp[i][j] will give us the number of schemes 
        // with profit >=i achieved by EXACTLY j people. 
        for(int i=0;i<group.size();i++){
            int  a= group[i];
            int  b= profit[i];
            for(int j=minProfit;j>=0;j--){
                for(int k=n-a;k>=0;k--){
                    dp[min(j+b, minProfit)][k+a]=(dp[min(j+b, minProfit)][k+a]+ dp[j][k])%mod;
                }
            }
        }
        int ans=0;
        for(auto x: dp[minProfit]){
            ans= (ans+x)%mod;
        }
        return ans;
    }
};