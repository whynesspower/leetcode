class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>ans;
        int n=graph.size();
        vector<vector<int>>AdjList(n);
        // AdjList[i] will give a list of all the nodes which are 
        // having a outgoing edge to the ith node. 
        vector<int>safe(n);
        queue<int>q;
        vector<int>OutDegree(n);
        for(int i=0;i<n; i++){
            for(int x: graph[i]){
                AdjList[x].push_back(i);
            }
            OutDegree[i]=graph[i].size();
            if(OutDegree[i]==0)q.push(i);
        }
        
        while(q.size()){
            int u=q.front();
            q.pop();
            safe[u]=1;
            for(auto x: AdjList[u]){
                if(--OutDegree[x]==0) q.push(x);
            }
        }
        
        for(int i=0;i<n;i++){
            if(safe[i]) ans.push_back(i);
        }
        return ans;
    }
};