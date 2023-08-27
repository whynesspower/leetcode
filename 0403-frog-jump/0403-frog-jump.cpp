#define ll long long
class Solution {

public:
    bool ifPossible(int i, int k, vector<int>& stones, map<pair<ll, ll>, bool>& dp) {
        if(i>stones.size()) return false;
        if (i == stones.size()-1) return true;
        if (dp.find({i, k}) != dp.end()) {
            return dp[{i, k}];
        }
        
        bool a = false, b = false, c = false;
        auto itr= stones.begin() + i + 1;
        auto findAtK  = lower_bound(itr, stones.end(), k+stones[i]);
        auto findAtK1 = lower_bound(itr, stones.end(), k + 1+stones[i]);
        auto findAtK_ = lower_bound(itr, stones.end(), k - 1+stones[i]);
        
        if (findAtK != stones.end() && *findAtK == k+stones[i]) {
             int nextI = static_cast<int>(findAtK - stones.begin());
            a = ifPossible(nextI, k, stones, dp);
        }
        if (findAtK1 != stones.end() && *findAtK1 == (k + 1+stones[i])) {
            int nextI = static_cast<int>(findAtK1 - stones.begin());
            b = ifPossible( nextI, k + 1, stones, dp);
        }
        if (findAtK_ != stones.end() && *findAtK_ == (k - 1+stones[i])) {
            int nextI = static_cast<int>(findAtK_ - stones.begin());
            c = ifPossible( nextI, k - 1, stones, dp);
        }
        cout<<"value of I: "<< i<<" Value of a, b, c: "<<a<<" "<<b<<" "<<c<<endl;
        dp[{i, k}] = a | b;
        dp[{i, k}] |= c;
        return dp[{i, k}];
        
    }

    bool canCross(vector<int>& stones) {
        int n = stones.size();
        map<pair<ll, ll>, bool> dp;
        if (stones[1] != 1) return false;
        if (stones.size() == 2) return true;
        return ifPossible(1, 1, stones, dp);
    }
};
