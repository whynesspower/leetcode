class Solution {
public:
    bool solve(vector<int>&nums, int k, int mid){
        vector<int>dp(nums.size(), 0);
        for(int i=nums.size()-1;i>=0;i--){
            if(i==nums.size()-1){
                dp[i]=nums[i]<=mid?1:0;
            }
            else if(i==nums.size()-2){
                dp[i]=(nums[i]<=mid?1:0 or dp[i+1]);
            }
            else{
                dp[i]=max(dp[i+1], (nums[i]<=mid?1:0)+dp[i+2]);
                // dp[i]=; 
            }
        }
        for(int i=0;i<dp.size();i++){
            if(dp[i]>=k){
                return true;
            }
        }
        return false;
    }
    
    
    
    int minCapability(vector<int>& nums, int k) {
        // this is binary search on answer
        int l=INT_MAX, r=INT_MIN;
        for(int i=0;i<nums.size();i++){
            l=min(l, nums[i]);
            r=max(r, nums[i]);
        }
        while(l<=r){
            int mid= (l+r)/2;
            // cout<<mid<<endl;
            // cout<<solve(nums, 7, 139)<<endl;
            if(solve(nums, k, mid)){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }

        return l;
    }
};