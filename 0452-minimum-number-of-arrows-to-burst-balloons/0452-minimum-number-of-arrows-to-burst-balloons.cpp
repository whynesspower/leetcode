class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& pt) {
        sort(pt.begin(), pt.end());
        int ans=0;
        for(int i=0;i<pt.size();i++){
            int l = pt[i][0];
            int r= pt[i][1];
            ans++;
            int j=i+1;
            while(j<pt.size()){
                int c=pt[j][0];
                int d=pt[j][1];
                if((c>=l and c<=r )or (d>=l and d<=r)){
                    j++;
                    l=max(l,c);
                    r=min(r, d);
                }
                else{
                    break;
                }
            }
            i=j-1;
        }
        return ans;
    }
};