class Solution {
public:
    void dfs( vector<int>adj[], int &ans, int i,  vector<bool>&vis){
        if(vis[i]==true) return;
        vis[i]=true;
        cout<<i<<" ";
        for(auto x:adj[i]){
            if(vis[x]==false){
                dfs(adj, ans,x, vis);
            }
        }
        return;
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n= isConnected.size();
        vector<int>adj[n];
        vector<bool>vis(n, false);
        for(int i=0;i<n;i++){
            for(int j=0;j<isConnected[i].size();j++){
                if(i==j)continue;
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                dfs(adj, ans, i, vis);
                // cout<<i<<" ";
                ans++;
            }    
        }
        return ans;
    }
};