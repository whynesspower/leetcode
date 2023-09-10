class Solution {
public:
    int countOrders(int n) {
        long ans=1;
        int mod=1e9+7;
        for(int i=1;i<=n;i++){
            ans=ans*(2*i-1)*i%mod;
        }
        return ans;
    }
};