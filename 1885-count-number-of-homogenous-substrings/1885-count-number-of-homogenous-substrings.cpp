class Solution {
public:
    int mod=1e9+7;
    int countHomogenous(string s) {
        int n=s.size();
        vector<int>dp(n, 1);

        for(int i=1;i<n;i++){
            if(s[i]!=s[i-1]) continue;
            else dp[i]=(dp[i-1]+1)%mod;
        }
        int ans=0;
        for(auto x: dp){
            ans=(ans+x)%mod;
        }
        return ans%mod;
    }
};