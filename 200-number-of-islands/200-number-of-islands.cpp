class Solution {
public:
    
    void dfs(vector<vector<bool>>&vis, int i, int j, int n ,int m,vector<vector<char>>& grid){
        if(i<0 or i>=n or j<0 or j>=m or grid[i][j]=='0' or vis[i][j]==true ){
            return ;
        }
        vis[i][j]=true;
        dfs(vis, i+1, j, n ,m, grid);
        dfs(vis, i-1, j, n ,m, grid);
        dfs(vis, i, j+1, n ,m, grid);
        dfs(vis, i, j-1, n ,m, grid);
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();//size of row
        int m=grid[0].size();//size of col
        vector<vector<bool>>vis(n, vector<bool>(m, false));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' and vis[i][j]==false){
                    dfs(vis, i, j, n, m, grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};