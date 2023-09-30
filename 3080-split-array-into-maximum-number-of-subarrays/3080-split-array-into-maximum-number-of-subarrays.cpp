class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int bit=INT_MAX;
        int ans=1;
        for(int i=0;i<nums.size();i++)
        {
            bit=nums[i]&bit;
            if(bit==0)
            {
                ans++;
                bit=INT_MAX;
            }
        }
        if(bit==INT_MAX||bit>0)ans--;
       
        
        return max(1,ans);
    }
};