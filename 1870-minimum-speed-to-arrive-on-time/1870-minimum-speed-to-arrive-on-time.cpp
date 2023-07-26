class Solution {
public:
    bool solve(int mid, vector<int>&dist, double hour){
        double time=0;
        for(int i=0;i<dist.size();i++){
            time+= double((double)dist[i]/(double)mid);
            if(time>hour) return false;
            else{
                if(i==dist.size()-1 and time<=hour){
                    return true;
                }
                time=ceil(time);
            }
        }
        return time<=hour;
    }
    
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l=0, r=1e7+10;
        bool ans=false;
        while(l<=r){
            int mid=(l+(r-l)/2);
            cout<<mid<<" ";
            if(solve(mid, dist, hour)){
                r=mid-1;
                ans=true;
            }
            else{
                l=mid+1;
            }
        }
        if(ans==false) return -1;
        return l;
    }
};