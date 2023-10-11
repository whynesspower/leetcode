class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int>startingTime;
        vector<int>endingTime;
        for(auto x:flowers){
            startingTime.push_back(x[0]);
            endingTime.push_back(x[1]);
        }
        sort(startingTime.begin(), startingTime.end());
        sort(endingTime.begin(), endingTime.end());
        vector<int>ans;
        for(auto x:people){
            auto itr1=upper_bound(startingTime.begin(), startingTime.end(), x);
            itr1--;
            int a= itr1-startingTime.begin();
            auto itr2=lower_bound(endingTime.begin(), endingTime.end(), x);
            itr2--;
            int b= itr2-endingTime.begin();
            int c= abs(a-b);
            ans.push_back(c);
        }
        return ans;
    }
};