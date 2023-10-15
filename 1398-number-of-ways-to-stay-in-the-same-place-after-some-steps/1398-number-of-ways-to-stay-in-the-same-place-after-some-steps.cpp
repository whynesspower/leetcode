class Solution {
private: 
    const int MOD=1e9+7;
    vector<vector<int>>dp;
public:

    int solve(int currIndx, int remSteps, int &n){
        if(currIndx<0) return 0;
        if(currIndx>=n) return 0;
        if(currIndx>(remSteps)) return 0;
        if(dp[currIndx][remSteps]!=-1) return dp[currIndx][remSteps];
        if(currIndx==0 and remSteps==0){
            dp[currIndx][remSteps]=1;
            return 1;
        } 
            
        int a=(solve(currIndx+1, remSteps-1, n)%MOD);
        a=(a+(solve(currIndx, remSteps-1, n))%MOD)%MOD;
        a=(a+(solve(currIndx-1, remSteps-1, n))%MOD)%MOD;
        dp[currIndx][remSteps]=a;
        return a;
    }
    int numWays(int steps, int arrLen) {
        int n=min(arrLen, steps/2+1);
        dp.resize(n, vector<int>(steps+1, -1));
        return solve(0, steps, n);
    }
};