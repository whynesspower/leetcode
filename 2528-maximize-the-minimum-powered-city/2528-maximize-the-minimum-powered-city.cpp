class Solution {
public:
    bool possible(vector<int>& st, long long mid, int r, int k){
        long long n=st.size();
        vector<long long>add(n, 0);
        long long currsum=0;
        for(long long i=0;i<r;i++){
            currsum+=st[i];
        }
        for(long long i=0;i<n;i++){
            if((i+r)<n){
                currsum+=st[i+r];
                currsum+=add[i+r];
            }
            if(currsum<mid){
                long long need=mid-currsum;
                if(need>k) return false;
                k-=need;
                currsum=mid;
                add[min(n-1, i+r)]=need;
                
            }
            if((i-r)>=0){
                currsum-=st[i-r];
                currsum-=add[i-r];
            }
        }
        return true;
    }
    
    long long maxPower(vector<int>& stations, int r, int k) {
        long long sum=0;
        for(auto it:stations) sum+=it;
        long long l=0, h=sum+k, ans=INT_MIN;
        while(l<=h){
            long long mid=l+(h-l)/2;
            if(possible(stations, mid, r, k)){
                l=mid+1;
                ans=max(mid, ans);
            }
            else{
                h=mid-1;
            }
        }
        return ans;
    }
};