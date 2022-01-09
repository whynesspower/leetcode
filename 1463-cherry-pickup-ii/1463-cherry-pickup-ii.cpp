class Solution {
public:
    int dp[80][80][80];
    int temp(vector<vector<int>>&grid, int r, int c1, int c2){
        
        int n=grid.size();
        int m=grid[0].size();
        if(r==n) return 0;
        if( dp[r][c1][c2]!=-1){
            return  dp[r][c1][c2];
        }
    
        int ans=0;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                int C1= i+c1;
                int C2= j+c2;
                if(C1>=0 and C1<m and C2>=0 and C2<m){
                    ans= max(ans,temp(grid, r+1, C1, C2));
                }
            }
        }
        if(c1==c2) ans=+grid[r][c1];
        else ans+=grid[r][c1]+grid[r][c2];
        return dp[r][c1][c2]=ans;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        int n=grid.size();
        int m=grid[0].size();
        return temp(grid, 0, 0, m-1);
    }
};