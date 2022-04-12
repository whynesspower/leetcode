class Solution {
public:
    
    int cnt(vector<vector<int>>&temp, int ii , int jj){
        int row[8]={-1,-1,-1,0,+1,+1,+1,0};
        int col[8]={0 ,+1,-1,1,+1,0 ,-1,-1};
        int countOfLive=0;
        for(int i=0;i<8;i++){
            int xx= row[i] + ii;
            int yy= col[i] + jj;
            if(xx>=0 and xx<temp.size() and yy>=0 and yy<temp[0].size()){
                if(temp[xx][yy]==1){
                    countOfLive++;
                }
            }
        }
        return countOfLive;
    
    }
    
    
    void gameOfLife(vector<vector<int>>& grid) {
        
        int n= grid.size();// no of rows
        int m= grid[0].size();// no of col
        vector<vector<int>> temp( n , vector<int> (m, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m ;j++){
                temp[i][j]=grid[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m ;j++){
                // temp[i][j]=grid[i][j];
                
                if(grid[i][j]){
                    int cntt= cnt(temp, i, j);
                    if(cntt< 2){
                        grid[i][j]=0;
                    }
                    else if(cntt==2 or cntt==3){
                        continue;
                    }
                    else if(cntt>3){
                        grid[i][j]=0;
                    }
                }
                else{
                    int cntt= cnt(temp, i, j);
                    if(cntt==3){
                        grid[i][j]=1;
                    }
                }
                
            }
        }
        
    }
};