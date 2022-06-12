class Solution {
public:
    int dfs(int i, int j,vector<vector<int>>&grid, vector<vector<int>>&moveCost, vector<vector<int>>&memo){
        if(i==grid.size()-1){
            return grid[i][j];
        }
        if(memo[i][j]!=-1){
            return memo[i][j];
        }
        int tempans=INT_MAX;
        for(int k=0;k<grid[0].size();k++){
            tempans=min(tempans, grid[i][j]+dfs(i+1, k, grid, moveCost, memo)+moveCost[grid[i][j]][k]);
        }
        return memo[i][j]=tempans;
    }
    
    
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>memo(m, vector<int>(n,-1));
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            ans=min(ans, dfs(0,i, grid, moveCost, memo));
        }
        return ans;
    }
};