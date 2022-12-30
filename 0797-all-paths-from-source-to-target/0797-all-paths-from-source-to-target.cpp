class Solution {
public:
    
    vector<vector<int>>ans;
    void dfs(vector<vector<int>>adj, vector<int>&temp, int &source, int desti ){
        temp.push_back(source);
        if(desti==source){
            ans.push_back(temp);
            return;
        }
        for(auto it:adj[source]){
            // if()
            dfs(adj, temp,it, desti );   
            temp.pop_back();
        }
        
    }
    
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<graph.size();i++){
            for(auto it:graph[i]){
                adj[i].push_back(it);
            }     
        }
        
        for(int i=0;i<adj[0].size();i++){
            vector<int>temp;
            temp.push_back(0);
            dfs(adj, temp, adj[0][i], n-1);
        }
        return ans;
    }
};