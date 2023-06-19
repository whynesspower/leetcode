class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans=0;
        int currsum=0;
        for(int i=0;i<gain.size();i++){
            currsum=(gain[i]+currsum);
            cout<<currsum<<" ";
            ans=max(currsum,ans);
        }
        return ans;
    }
};