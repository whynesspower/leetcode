class Solution {
public:
    double champagneTower(int poured, int r, int c) {
        vector<vector<double>>dp(100, vector<double>(100,-1));
        int n=100;
        dp[0][0]=poured;
        for(int i=1;i<n;i++){
            for(int j=0;j<=i;j++){
                double sum=0;
                if(j-1>=0){
                    if(dp[i-1][j-1]>1)
                        sum+=dp[i-1][j-1]-1;
                }
                if(dp[i-1][j]>1)
                    sum+=dp[i-1][j]-1;

                sum/=2.0;
                // if(sum>=1){
                //     sum=1;
                // }
                dp[i][j]=sum;
            }
            
        }
        return dp[r][c]>=1.0? 1.0: dp[r][c];
    }
};