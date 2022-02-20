class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int ans=1;
        int a=intervals[0][0];
        int b=intervals[0][1];
        
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>a and intervals[i][1]>b){
                ans++;
            }
            if(intervals[i][1]>b){
                a=intervals[i][0];
                b=intervals[i][1];
            }
        }
        
        
        return ans;
    }
};