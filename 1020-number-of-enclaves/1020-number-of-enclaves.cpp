class Solution {
public:
    int n, m;
    void dfs(vector<vector<int>>& grid,  int i, int j){
        if(i<0 or i>=n or j<0 or j>=m ) return;
        if(grid[i][j]==0) return;
        grid[i][j]=0;
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int ans=0;
         n=grid.size();
         m=grid[0].size();
        for(int j=0;j<m;j++){
            dfs(grid, 0, j);
        }
        
        for(int j=0;j<m;j++){
            dfs(grid, n-1, j);
        }
        
        for(int j=0;j<n;j++){
            dfs(grid, j, 0);
        }
        
        for(int j=0;j<n;j++){
            dfs(grid,j, m-1 );
        }
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    ans++;
                }
            }
        }
        return ans;
    }
};