#define ll long long
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        ll n=nums.size();
        for(ll i=0;i<n;i++){
            nums.push_back(-1);
        }
        ll m= n;
        m= m+m;
        nums.push_back(-1);
        // nums.resize(2*n);
        // n to 2*N-1
        for(ll i=0;i<n;i++){
            if(nums[i]>0){
                if(n+nums[i]<=(m))
                    nums[n+nums[i]]=1;
            }
        }
        for(ll i=n+1;i<=m;i++){
            if(nums[i]==-1){
                return i-n;
            }
        }
        return n+1;
    }
};