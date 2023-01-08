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
                if(x1-x2==0) mp[-90]++;
                else{
                    double m= (double)((double)(y2-y1)/(double)(x2-x1));
                    mp[m]++;
                }
                int temp=0;
                for(auto it:mp){
                    temp=max(temp, it.second+1);
                }
                ans=max(ans, temp);
                // double c= (double)(y1-(double)m*(double)x1);
                // string res="";
                // res+=to_string(m);
                // res+=" ";
                // res+=to_string(c);
                // // res+=" ";/
                // // res+=to_string(-y1);
                // mp[res] ++;
            }
        }
        // double ans=INT_MIN;
        // for(auto it:mp){
        //     cout<<it.first<<endl;
        //     ans=max(ans, it.second);
        // }
        return ans;
    }
};