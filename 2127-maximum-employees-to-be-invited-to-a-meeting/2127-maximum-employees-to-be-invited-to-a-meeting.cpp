class Solution {
public:
    vector<vector<int>>adj;
    int n;
    vector<bool>vis;
    int dfs(int node){
        vis[node]=true;
        int dist=0;
        for(auto it:adj[node]){
            dist=max(dist,dfs(it));   
        }
        return dist+1;
    }
    
    
    int maximumInvitations(vector<int>& fav) {
        int n=fav.size();
        adj.resize(n);
        vis.resize(n, false);
        for(int i=0;i<n;i++){
            if(fav[fav[i]]!=i)
                adj[fav[i]].push_back(i);
        }
        int dis1=0;
        for(int i=0;i<n;i++){
            if(fav[fav[i]]==i){
                dis1+=dfs(i);
            }
        }
        for(int i=0;i<n;i++){
            int j=i;
            int cnt=0;
            for(;!vis[j]; j=fav[j]){
                cnt++;
                vis[j]=true;
            }
            for(int k=i;k!=j;k=fav[k]){
                cnt--;
            }
            dis1=max(dis1, cnt);
        }
        
        return dis1;
    }
};