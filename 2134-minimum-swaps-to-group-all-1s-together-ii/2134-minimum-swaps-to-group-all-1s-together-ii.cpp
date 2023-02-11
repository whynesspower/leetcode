class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n =nums.size();
        vector<int>allnums;
        int cnt1=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1)cnt1++;
            allnums.push_back(nums[i]);
        }
        for(int i=0;i<n;i++){
            allnums.push_back(nums[i]);
        }
        int curr0=0;
        int l=0,r=0;
        int ans=INT_MAX;

        while(r<cnt1){
            if(allnums[r]==0) curr0++;
            r++;
            // continue
        }
            // window is from [r-1 to l]

        ans=min(ans, curr0);
               
        // r--;
        while(l<n){
            if(allnums[r]==0)curr0++;
            if(allnums[l]==0)curr0--;
            l++;
            r++;
            ans=min(ans, curr0);
        }
        return ans;
    }
};