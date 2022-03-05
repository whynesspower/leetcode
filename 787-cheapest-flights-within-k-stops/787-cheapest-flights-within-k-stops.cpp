typedef priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> MinHeap;
 
//Graph data structure, implemented with adjacency list
class Graph{
public:
    vector<vector<pair<int,int>>> adj;
    int nNodes;
    void generateGraph(vector<vector<int>> &input, int n){
        nNodes = n;
        adj.resize(nNodes+1);
        for(int i=0; i<input.size(); i++){
            adj[input[i][0]].push_back({input[i][1], input[i][2]});
        }
    }
    
    void clear(){
        adj.clear();
    }
};
 
int dijkstraSingleTarget(Graph g, int source, int target, int k){
    MinHeap minHeap;
    vector<int> dist(g.nNodes+1, INT_MAX);
    vector<int> stops(g.nNodes+1, INT_MAX);
    
    dist[source] = 0;
    stops[source] = 0;
    minHeap.push({0, source, 0});
    
    while(!minHeap.empty()){
        auto [curDist, curNode, curStops] = minHeap.top();
        minHeap.pop();
        if(curNode == target) return curDist;
        if(curStops == k+1) continue;
        for(auto &[nextNode, nextWeight] : g.adj[curNode]){
            int nextDist = curDist + nextWeight;
            int nextStops = curStops + 1;
            if(nextDist < dist[nextNode] || nextStops < stops[nextNode]){
                dist[nextNode] = nextDist;
                stops[nextNode] = nextStops;
                minHeap.push({nextDist, nextNode, nextStops});
            }
        }
    }
    return -1;
}
 
 
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        Graph g;
        g.generateGraph(flights, n);
        return dijkstraSingleTarget(g, src, dst, k);
    }
};
 
 
 
 
 
 
 
 