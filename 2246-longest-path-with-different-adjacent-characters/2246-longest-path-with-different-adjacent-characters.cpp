class Solution {
public:
    vector<int>vis;
    
    // dfs return the max value 
    int dfs(vector<int>adj[], int src, string &s){
        vis[src]=1;
        // pq.push(1);
        
        // priority_queue<int>pq;
        int mx1=0, mx2=0;
        for(auto it:adj[src]){
            if(vis[it]==-1 and s[src]!=s[it]){
                int a=dfs(adj, it, s);
                if(a>mx1){
                    mx2=mx1;
                    mx1=a;
                }
                else{
                    mx2=max(a, mx2);
                }
            }
        }
        int ans=1+mx1+mx2;
        // int a;
        // if(pq.empty()==false) a=pq.top();
        // int k=2;
        // while(!pq.empty() and k--){
        //     int temp = pq.top();
        //     pq.pop();
        //     ans+=temp;
        // }
        vis[src]=ans;
        return 1+mx1;
    }
    
    
    int longestPath(vector<int>& parent, string s) {
        int n=parent.size();
        vis.resize(n,-1);
        vector<int>adj[n+1];
        for(int i=1;i<parent.size();i++){
            adj[i].push_back(parent[i]);
            adj[parent[i]].push_back(i);
        }
        
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                dfs(adj, i, s);
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<vis.size();i++){
            ans=max(ans, vis[i]);
        }
        return ans;
    }
};