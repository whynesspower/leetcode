class Solution {
public:
    int minExtraChar(string s, vector<string>& d) {
        int n=s.length();
        unordered_set<string>st(d.begin(), d.end());
        vector<int>dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            dp[i]=dp[i-1]+1;
            for(int len=1;len<=i;len++){
                if(st.find(s.substr(i-len, len))!=st.end() ){
                    dp[i]=min(dp[i], dp[i-len]);
                }
            }
        }
        return dp[s.size()];
    }
};