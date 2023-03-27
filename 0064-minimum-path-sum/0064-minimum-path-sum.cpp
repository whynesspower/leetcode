class Solution {
public:
    int n,m;
    int dfs(int i, int j, vector<vector<int>>&dp, vector<vector<int>>&grid){
        if(i<0 or j<0 or i>=n or j>=m) return INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==n-1 and j==m-1){
            dp[i][j]=grid[i][j];
            return grid[i][j];
        }
        int a= dfs(i+1, j, dp, grid);
        int b= dfs(i, j+1, dp, grid);
        dp[i][j]=min(a,b)+ grid[i][j];
        return dp[i][j];
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        n= grid.size();
        m=grid[0].size();
        vector<vector<int>>dp(n, vector<int>(m,-1));
        dfs(0,0, dp, grid);
        return dp[0][0];
    }
};