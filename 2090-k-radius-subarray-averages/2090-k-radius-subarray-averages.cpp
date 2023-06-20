#define ll long long 
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        ll n=nums.size();
        vector<int> ans(n,-1);
        vector<ll> presum(n+1,0);
        presum[0]=nums[0];
        for(int i=1;i<n;i++){
            presum[i]=presum[i-1]+nums[i];
        }
        // n=4
        // 0, 1, 2,  3
        // 7,11, 14, 23
        for(ll i=k;i<n-k;i++){
            ll sum= presum[i+k]-((i-k)<=0?0:presum[i-k-1]);
            ll average= (sum/(2*k+1));
            ans[i]=average;
        }
        return ans;
    }
};