class Solution {
public:
    int strangePrinter(string s) {
        int n=s.size();
        if(n==0){
            return 0;
        }
        vector<vector<int>>dp(n, vector<int>(n));
        for(int i=0;i<n;i++){
            dp[i][i]=1;
            if(i<n-1){
                dp[i][i+1]=s[i]==s[i+1]?1:2;
            }
        }
        for(int len=2;len<n;len++){
            for(int start=0;start+len<n;start++){
                dp[start][start+len]=len+1;
                for(int k=0;k<len;k++){
                    int currdist=dp[start][start+k] + dp[start+k+1][start+len];
                    dp[start][start+len]=min(dp[start][start+len], s[start+k]==s[start+len]?currdist-1: currdist);
                    
                }
            }
        }
        return dp[0][n-1];
    }
};