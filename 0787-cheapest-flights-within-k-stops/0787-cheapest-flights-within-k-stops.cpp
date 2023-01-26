
class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<pair<int, int>> adj[n];
        // destrination, cost

        for (auto &it : flights)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        // stops, node, cost
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            if (stops > k)
                continue;
            for (auto itr : adj[node])
            {
                if (dist[itr.first] > (cost + itr.second) and stops <= k)
                {
                    dist[itr.first] = cost + itr.second;
                    q.push({stops + 1, {itr.first, cost + itr.second}});
                }
            }
        }
        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};
