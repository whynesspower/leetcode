class Solution {
public:
    bool flag =false;
    
    
    vector<int>adj[200001];
    
    void dfs(int source, vector<int>&visited ){
        visited[source]=true;
        
        for(auto x:adj[source]){
            if(visited[x]==false and x!=source ){
                dfs(x, visited);
            }
        }
        
    }
    
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int desti) {
        vector<int>visited(n,0);
        
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            
        }
        dfs(source, visited);
        
        return visited[desti];
    }
};