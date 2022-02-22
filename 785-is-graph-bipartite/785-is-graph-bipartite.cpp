class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<int>visited(v, 0);
        
        for(int i=0;i<v;i++){
            if(!visited[i]){
                
                queue<int>q;
                q.push(i);
                visited[i]=1;
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    for(auto x:graph[node]){
                        if(visited[x]==0){
        
                            q.push(x);
                            visited[x]=-visited[node];

                        }
                        else if(visited[x]==visited[node]){
                            return false;
                        }
                        
                    }
                }
                
            }
            
        }
        
        return true;
    }
};