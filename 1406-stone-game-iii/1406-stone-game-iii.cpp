class Solution {
    int seen[50005];
    bool visited[50005];
    int maxWin(vector<int>& stoneValue, int idx) {
        if (idx == stoneValue.size())
            return 0;
        
        if (visited[idx])
            return seen[idx];
        
        int res = INT_MIN;
        int myStone = 0;
        for (int i = idx; i < stoneValue.size() & i < idx + 3; i++) {
            myStone += stoneValue[i];
            res = max(res, myStone - maxWin(stoneValue, i + 1));
        }
        visited[idx] = true;
        seen[idx] = res;
        return res;
    }
    
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int res = maxWin(stoneValue, 0);
        if (res > 0)
            return "Alice";
        else if (res < 0)
            return "Bob";
        else
            return "Tie";
    }
};