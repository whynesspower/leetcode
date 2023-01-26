
class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        // flights -> (src, dst, wt)
        vector<int> dist(n, 1e9);
        dist[src]=0;
        for (int i = 0; i < k + 1; i++)
        {
            vector<int> temp(dist);
            for (auto &it : flights)
            {
                temp[it[1]] = min(dist[it[0]] + it[2], temp[it[1]]);
            }
            dist = temp;
        }
        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};
