class Solution {
public:
    int len;
    int minCost(int N, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        int n = cuts.size();
        len=N;
        vector<vector<int>>dp(n+1, vector<int>(n+1,0));
        return helper(N, 0, n, cuts, dp);
    }
    int helper(int n, int si, int ei, vector<int>&cuts, vector<vector<int>>&dp ){
        if(si>=ei) return 0;
        if(dp[si][ei]!=0) return dp[si][ei];
        int ans=INT_MAX;
        for(int k=si;k<ei;k++){
            int le= si==0?0:cuts[si-1];
            int re= ei==cuts.size()?len:cuts[ei];
            int cost= re-le;
            int left=helper(le, si, k, cuts, dp);
            int right=helper(re,k+1, ei, cuts, dp);
            
            int currans=left+right+cost;
            ans=min(currans, ans);
        }
        return dp[si][ei]=ans;
    }
};