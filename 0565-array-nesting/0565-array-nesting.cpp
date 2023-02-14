class Solution {
public:
    // dfs returns the size of maximum cycle we have starting
    // from the index "i"
    int dfs(int i, vector<int>adj[], vector<bool>&vis){
        if(vis[i]==true) return 0;
        vis[i]=true;
        int a= 1;
        for(auto x: adj[i]){
            if(vis[x]==false){
                a+= dfs(x, adj, vis);
            }
        }
        return a;
    }
    
    
    
    int arrayNesting(vector<int>& nums) {
        int n=nums.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            adj[i].push_back(nums[i]);
            // adj[nums[i]].push_back(i);
        }
        vector<bool>vis(n, false);
        int ans=INT_MIN;
        
        for(int i=0;i<n;i++){
            if(!vis[i])
                ans=max(ans, dfs(i, adj, vis));
        }
        
        return ans;
    }
};