class Solution {
public:
    int rob(vector<int>& A) {
        if(size(A) == 1) return A[0];
        vector<int> dp(A.size());
        dp[0]=A[0];
        dp[1] = max(A[0], A[1]);
        for(int i = 2; i < size(A); i++)
            dp[i] = max(dp[i-1], A[i] + dp[i-2]);
        return dp.back();
    }
};