class Solution {
public:
    int maxPoints(vector<vector<int>>& p) {
        int ans=1;
        for(int i=0;i<p.size()-1;i++){
            unordered_map<double,int>mp;
            for(int j=i+1;j<p.size();j++){
                int x1=p[i][0];
                int y1=p[i][1];
                int x2=p[j][0];
                int y2=p[j][1];
                if(x1-x2==0) mp[INT_MAX]++;
                else{
                    double m= (double)((double)(y2-y1)/(double)(x2-x1));
                    mp[m]++;
                }
                int temp=0;
                for(auto it:mp){
                    temp=max(temp, it.second+1);
                }
                ans=max(ans, temp);
            }
        }
        return ans;
    }
};