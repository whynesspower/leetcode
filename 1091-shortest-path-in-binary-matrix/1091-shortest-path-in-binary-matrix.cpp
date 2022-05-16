class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n= grid.size();
        int m=grid[0].size();
        if(n==0 or m==0){
            return -1;
        }
        if(grid[0][0]!=0 or grid[n-1][n-1]!=0) return -1;
        vector<vector<int>>directions={{1,1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}};
        queue<pair<int, int>>q;
        q.push({0,0});
        grid[0][0]=1;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int x= it.first;
            int y= it.second;
            if(x==n-1 and y==n-1){
                return grid[x][y];
            }
            
            for(auto k:directions ){
                int nx= k[0]+x ;
                int ny= k[1]+y ;
                if(nx>=0 and nx< n and ny>=0 and ny< n and grid[nx][ny]==0){
                    grid[nx][ny]=grid[x][y]+1;
                    q.push({nx, ny});
                }
            }
        }
        return -1;
    }
};