class Solution {
public:
    vector<int>parents;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        for(int i=0;i<=n;i++){
            parents.push_back(i);
        }
        for(auto edge:edges){
            int u=find(edge[0]);
            int v=find(edge[1]);
            if(u==v){
                return edge;
            }
            else{
                unnion(edge[0], edge[1]);
            }            
        }
        return {};
    }
    
    int find(int node){
        while(parents[node]!=node){
            node=parents[node];
        }
        
        return node;
    }
    
    void unnion(int i, int j){
        int iroot=find(i);
        int jroot=find(j);
        
        if(iroot!=jroot){
            parents[jroot]=iroot;
        }
         
    }
    
};