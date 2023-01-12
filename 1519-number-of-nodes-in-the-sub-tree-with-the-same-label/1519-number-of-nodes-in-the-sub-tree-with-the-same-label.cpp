class Solution {
public:
    vector<int>ans;
    vector<int>dfs(vector<vector<int>>&adj, string &s, int node, vector<bool>&vis){
        vis[node]=true;
        vector<int>temp(26,0);
        for(auto x: adj[node]){
            if(vis[x]==false){
                vector<int>t=dfs(adj, s, x, vis);
                for(int i=0;i<26;i++){
                    temp[i]+=t[i];
                }
            }
        }
        temp[s[node]-'a']++;
        int a=temp[s[node]-'a'];
        ans[node]=a;
        return temp;
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>>adj(n+1);
        for(auto x:edges){
            int a= x[0];
            int b= x[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<bool>vis(n, false);
        ans.resize(n, -1);
        dfs(adj, labels, 0, vis);
        return ans;
    }
};