class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size()-1;
        // 0,2  1,1,  2,0
        
        // 0,3  1,2  2,1  3,0
        
        
        // 0,0   1,1,  2,2  
        int ans=0;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(i==j){
                    ans+= mat[i][j];
                }
                if(i==n-j){
                    ans+= mat[i][j];
                }
            }
        }
        if(n&1){
            return ans;
        }
        else return ans-mat[n/2][n/2];
        
    }
};