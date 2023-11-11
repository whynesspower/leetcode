class Graph {

private:
    vector<vector<pair<int,int>>>adj;
public:
    Graph(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        for(auto e: edges){
            int a= e[0];
            int b= e[1];
            int c= e[2];
            adj[a].push_back({b,c});
            // from a to b with cost c
        }
    }
    
    void addEdge(vector<int> e) {
        int a= e[0];
        int b= e[1];
        int c= e[2];
        adj[a].push_back({b,c});
    }
    
    int shortestPath(int node1, int node2) {
        int n = adj.size();
        vector<int> dist(n, INT_MAX);
        dist[node1] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, node1});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (const auto& edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;

                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        return (dist[node2] == INT_MAX)? -1 : dist[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */