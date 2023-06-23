class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1, vector<int>(1003, 0));
        // dp[i][diff]  will give you length of highest 
        // ap at index 'i' with difference of 'diff'
        if(n<=2) return n;
        if(n>=3){
            int firstDiff=nums[1]-nums[0];
            if(firstDiff>=0) dp[1][firstDiff]=1;
            else dp[1][firstDiff+1003]=1;
            for(int i=2;i<n;i++){
                for(int j=0;j<i;j++){
                    int diff=nums[i]-nums[j];
                    if(diff>=0){
                        dp[i][diff]= dp[j][diff]+1;
                    }
                    else{
                        dp[i][diff+1003]=dp[j][diff+1003]+1;
                    }

                }
            }
        }
        int ans=INT_MIN;
        for(int j=0;j<n;j++){
            for(int i=0;i<1003;i++){
                ans=max(ans, dp[j][i]);
            }
        }
        return ans+1;
    }
};