class Solution {
public:
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        vector<vector<int>> g(n);
        for(auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        long long ans = 0;
        function<vector<long long>(int, int)> dfs = [&] (int now, int pre) ->vector<long long> {
            vector<long long> cur_max = {price[now], 0};
            for(auto& nei : g[now]) {
                if(nei != pre) {
                    auto&& sub = dfs(nei, now);
                    ans = max(ans, cur_max[0] + sub[1]);
                    ans = max(ans, cur_max[1] + sub[0]);
                    cur_max[0] = max(cur_max[0], sub[0] + price[now]);
                    cur_max[1] = max(cur_max[1], sub[1] + price[now]);
                }
            }
            return cur_max;
        };
        dfs(0, -1);
        return ans;
    }
};