class Solution {
public:
   int minimumDeleteSum(string a, string b) {
        
    int n = a.size();
    int m = b.size();
    vector<vector<int>> dp(n+1 , vector<int> (m+1));

    for(int i=1 ; i<=n ; i++)                 // base case filling up
        dp[i][0] = dp[i-1][0] + a[i-1];

    for(int j=1; j<=m ; j++)                 // base case filling up
        dp[0][j] = dp[0][j-1] + b[j-1];

    for(int i=1 ; i<=n ; i++)
    {
        for(int j=1 ; j<=m ; j++)
        {
            if(a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = min( dp[i-1][j] + a[i-1] ,
                                dp[i][j-1] + b[j-1] );
        }
    }
    return dp[n][m];
    }
};