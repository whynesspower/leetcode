class Solution {
public:
    vector<vector<int>>adj;
    int n;
    int ans=-1;
    vector<bool>vis;
    void dfs(int node, int d, unordered_map<int,int>&mp){
        vis[node]=1;
        mp[node]=d;
        for(auto it:adj[node]){
            if(vis[it]==false){
                dfs(it, d+1, mp);
            }
            else if(mp.count(it)){
                ans=max(ans, d-mp[it]+1);
            }
        }
    }
    
    
    
    int longestCycle(vector<int>& edges) {
        n=edges.size();
        adj.resize(n);
        vis.resize(n, false);
        for(int i=0;i<n;i++){
            if(edges[i]!=-1){
                adj[i].push_back(edges[i]);
            }
        }
        for(int i=0;i<n;i++){
            unordered_map<int,int>mp;
            if(vis[i]==false){
                dfs(i,0, mp);
            }
            
        }
        return ans;
    }
};