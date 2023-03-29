class Solution {
public:
    int dp[501][501]={};
    int dfs(vector<int>&s, int i, int t){
        if(i>=s.size()) return 0;
        if(dp[i][t]) return dp[i][t];
        return dp[i][t]= max(dfs(s, i+1, t), dfs(s,i+1,t+1)+ s[i]*t);
    }
    
    int maxSatisfaction(vector<int>& s) {
        sort(s.begin(), s.end());
        return dfs(s, 0, 1);
    }
};