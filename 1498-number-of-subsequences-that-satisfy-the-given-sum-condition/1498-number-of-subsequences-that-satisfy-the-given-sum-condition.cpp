class Solution {
public:
    long long binpow(long long a, long long b, long long m)
    {
        a %= m;
        long long res = 1;
        while (b > 0)
        {
            if (b & 1)
            res = res * a % m;
            a = a * a % m;
            b >>= 1;
        }
        return res;
    }
    int numSubseq(vector<int>& nums, int target) {
        long long mod= 1e9+7;
        sort(begin(nums), end(nums));
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(2*nums[i]>target){
                break;
            }
            auto it=  upper_bound(nums.begin() + i, nums.end(), target-nums[i]);
            it--;
            int indx=it-nums.begin();
            int n= indx-i;
            // cout<<indx<<" ";
            // n = pow(2, n, mod);
            long long m= binpow(2, n, mod);
            ans= (m + ans)%mod;
            // if(it==nums.begin()){
            //     continue;
            // }   
        }
        return ans%mod;
    }
};