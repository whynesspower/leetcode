class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        // sort(nums.begin(), nums.end());
        vector<int>dp;
        
        for(int i=0;i<nums.size();i++){
            int index= lower_bound(dp.begin(), dp.end(), nums[i])-dp.begin();
            if(index>=dp.size()){
                dp.push_back(nums[i]);
            }
            else{
                dp[index]=nums[i];
            }
        }
        
        return dp.size();
    }
};