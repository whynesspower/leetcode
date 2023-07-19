class Solution {
public:
    // Did by my own 
    int eraseOverlapIntervals(vector<vector<int>>& v) {
        sort(v.begin(), v.end());
        int i=0,j=0;
        int prevIndx=0, currIndx=1;
        int n=v.size();
        int cntOfRemovals=0;
        if(n<=1) return cntOfRemovals;
        while(currIndx<n){
            int x1=v[prevIndx][0];
            int y1=v[prevIndx][1];
            int x2=v[currIndx][0];
            int y2=v[currIndx][1];
            if(y1<=x2){
                prevIndx=currIndx;
                currIndx++;
                continue;
            }
            else{
                // collition occurs
                if(y1<=y2){
                    // prevIndx is smaller range, hence gredily chose this to be removed
                    cntOfRemovals++;
                    currIndx++;
                }
                else{
                    prevIndx=currIndx;
                    currIndx++;
                    cntOfRemovals++;
                }
            }
        }
        return cntOfRemovals;
    }
};