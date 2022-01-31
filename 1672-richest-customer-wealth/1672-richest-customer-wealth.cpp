class Solution {
public:
    int maximumWealth(vector<vector<int>>& acc) {
        int maxwel=INT_MIN;
        for(int i=0;i<acc.size();i++){
           int currsum=0;
            for(int j=0;j<acc[0].size();j++){
                currsum+=acc[i][j];
            }
            maxwel= max(maxwel, currsum);
        }
        return maxwel;
    }
};