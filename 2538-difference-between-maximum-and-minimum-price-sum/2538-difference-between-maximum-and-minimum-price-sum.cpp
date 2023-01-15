#define ll long long
class Solution {
public:
    vector<unordered_map<int, ll>>dp;
    long long dfs(vector<long long>adj[], ll src,  vector<int>& price, ll par){
        if(dp[src].count(par)){
            return dp[src][par];
        }
        
        ll subchilmax=0;
        for(auto it: adj[src]){
            if(it!=par){
                ll t=dfs(adj, it, price, src);
                subchilmax=max(t, subchilmax);
            }
        }
        dp[src][par]=subchilmax+price[src];
        return dp[src][par];
    }
    
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        vector<ll>adj[n];
        dp.resize(n);
        for(ll i=0;i<edges.size();i++){
            ll a=edges[i][0];
            ll b=edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        ll ans=0;
        for(ll i=0;i<n;i++){
            if (size(adj[i]) == 1){
                ans=max(ans, dfs(adj, i, price, -1ll)-price[i]);
            }
        }
        
        return ans;
    }
};