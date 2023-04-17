class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int b) {
        int a= INT_MIN;
        for(auto x: candies){
            a=max(a, x);
        }
        vector<bool>ans;
        for(auto x: candies){
            if(x+b>=a) ans.push_back(true);
            else ans.push_back(false);
        }

        return ans;
    }
};