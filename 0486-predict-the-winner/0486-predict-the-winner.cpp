class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i, int j,vector<int>&nums){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int x = nums[i]+ min(solve(i+1, j-1, nums), solve(i+2, j, nums));
        int y = nums[j] + min(solve(i+1, j-1, nums), solve(i, j-2, nums));
        return dp[i][j]= max(x, y);
    }
    
    
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n, vector<int>(n, -1));
        int a= solve(0, n-1, nums);
        int b=0;
        for(auto &x:nums){
            b+=x;
        }
        cout<<a<<" "<<b<<endl;
        int c=b-a;
        if(a>=c){
            return true;
        }
        return false;
    }
};