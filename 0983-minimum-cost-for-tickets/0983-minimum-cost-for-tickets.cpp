class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
      unordered_set<int> travel(begin(days), end(days));
      int dp[366] = {};
      for (int i = 1; i < 366; ++i) {
        if (travel.find(i) == travel.end()) dp[i] = dp[i - 1];
        else dp[i] = min({ dp[i - 1] + costs[0], dp[max(0, i - 7)] + costs[1], dp[max(0, i - 30)] + costs[2]});
      }
      return dp[365];
    }
};