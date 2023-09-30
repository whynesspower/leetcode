class Solution {
public:
    vector<int>dp;
    int ans=0;
    int dfs(int s, vector<int>adj[], vector<bool>&vis, int k){
        vis[s]=1;
        for(auto x:adj[s]){
            if(vis[x]==0){
                dp[s]+=dfs(x, adj, vis, k);
            }
        }
        if(dp[s]%k==0){
            ans++;
            return 0;
        }
        return dp[s];
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        dp.resize(n, 0);
        for(int i=0;i<values.size();i++){
            dp[i]=values[i];
        }
        vector<int>adj[n];
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(n, 0);
        dfs(0, adj, vis, k);
        return ans;
    }
};