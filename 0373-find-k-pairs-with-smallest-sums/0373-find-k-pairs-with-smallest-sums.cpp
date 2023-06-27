class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> res;
        if (m == 0 || n == 0) return res;
        for (int i = 0; i < m; i++) {
            pq.push({{nums1[i]+nums2[0]}, {i, 0}});
        }
        while (!pq.empty() && k-- > 0) {
            int val = pq.top().first, i = pq.top().second.first, j = pq.top().second.second;
            pq.pop();
            vector<int> v = {nums1[i], nums2[j]};
            res.push_back(v);
            if (j+1 == n) continue;
            pq.push({{nums1[i]+nums2[j+1]}, {i, j+1}});
        }
        return res;
    }
};