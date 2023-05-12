#define ll long long 
class Solution {
public:
    long long mostPoints(vector<vector<int>>& q) {
        ll n = q.size();
        vector<ll >dp(n);
        dp[n-1]=q[n-1][0];
        for(ll i=n-2;i>=0;i--){
            ll skips= q[i][1];
            ll t= q[i][0];
            dp[i]=max(t, dp[i+1]);
            if(i+skips+1<=n-1){
                dp[i]=max(dp[i+skips+1]+q[i][0], dp[i+1]);   
            }
        }
        ll ans= *max_element(dp.begin(), dp.end());
        return ans;
    }
};