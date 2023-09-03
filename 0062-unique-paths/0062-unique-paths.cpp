class Solution {
public:
    int count(vector<vector<int>>&dp, int i, int j){
        if(i==0 and j==0) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int ways=( (((i-1)>=0)?count(dp, i-1, j):0) + (((j-1)>=0)?count(dp, i, j-1):0) );
        dp[i][j]=ways;
        return ways;
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m , vector<int>(n, -1)); 
        dp[0][0]=1;
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(i==0 and j==0)continue;
        //         dp[i][j]=(((i-1)>=0)?dp[i-1][j]:0)+(((j-1)>=0)?dp[i][j-1]:0);
        //     }
        // }
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         // dp[i][j]=i-1>=0?dp[i-1][j]:0+(j-1)>=0?dp[i][j-1]:0;
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return count(dp, m-1, n-1);
        // return dp[m-1][n-1];
    }
};