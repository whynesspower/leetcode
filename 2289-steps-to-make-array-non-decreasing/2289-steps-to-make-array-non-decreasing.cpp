class Solution {
public:
    int totalSteps(vector<int>& nums) {
        vector<int>st, dp(nums.size());
        int ans=0;
        for(int i=nums.size()-1;i>=0;i--){
            while(st.empty()==false and nums[i]> nums[st.back()]){
                dp[i]=max(++dp[i], dp[st.back()]);
                ans=max(ans, dp[i]);
                st.pop_back();
            }
            
            st.push_back(i);
        }
        return ans;
    }
};