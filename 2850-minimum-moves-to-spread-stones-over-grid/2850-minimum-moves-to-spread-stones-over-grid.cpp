class Solution {
public:
    int countMinMoves(vector<vector<int>>& grid){
        bool flag=true;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(grid[i][j]!=1){
                    flag=false;
                    break;
                }
            }
        }
        
        if(flag){
            return 0;
        }
        
        int minCntToAll1s=INT_MAX;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    for(int l=0;l<3;l++){
                        if(grid[i][j]==0 and grid[k][l]>1){
                            grid[i][j]++;
                            grid[k][l]--;
                            int dist= abs(i-k) + abs(j-l);
                            minCntToAll1s=min(minCntToAll1s, dist+countMinMoves(grid));
                            grid[i][j]--;
                            grid[k][l]++;
                        }
                    }
                }
            }
        }
        return minCntToAll1s;
        
    }
    
    int minimumMoves(vector<vector<int>>& grid) {
        return countMinMoves(grid);
    }
};