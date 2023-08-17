class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        // vector<vector<int>>dp(n, vector<int>(m,-1));
        // dp of i will give i, j , count of the index 
        queue<vector<int>>q;
        // dp==-1 means unprocessed
        // dp==-2 means visited  
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    // dp[i][j]=0;
                    q.push({i, j, 0});
                }
                else{
                    mat[i][j]=-1;
                }
            }
        }
        vector<int> DIR={0, 1, 0, -1, 0};
        while(!q.empty()){
            auto x=q.front();
            int r=x[0];
            int c=x[1];
            int dist=x[2];
            // auto {r, c, dist} = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int new_row=r+DIR[i];
                int new_col=c+DIR[i+1];
                if(new_row<0 || new_row>=n || new_col<0 || new_col>=m || mat[new_row][new_col]!=-1)
                    continue;
                mat[new_row][new_col]=mat[r][c]+1;
                q.push({new_row, new_col, mat[new_row][new_col]});
            }
        }    
        return mat;
    }
};