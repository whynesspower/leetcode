#define ll long long 
class Solution {
public:
    ll n;
    
    bool solve(ll mx, ll l, ll r, vector<int>& nums ){
        
        vector<ll>pre(n, 0);
        pre[0]=mx-nums[0];
        if(pre[0]<0) return false;
        for(ll i=1;i<n;i++){
            pre[i]=pre[i-1]+ mx-nums[i];
            if(pre[i]<0) return false;
        }
        return true;
    }
    
    
    int minimizeArrayValue(vector<int>& nums) {
        n=nums.size();
        ll l=0, r= 1e9+7;
        while(l<=r){
            ll mid = l + (r-l)/2;
            if(solve(mid, l, r, nums)){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return r+1;
    }
};