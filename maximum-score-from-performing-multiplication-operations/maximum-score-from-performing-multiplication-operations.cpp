class Solution {
public:
    
    int temp[1001][1001];
    // memset(temp, 0, sizeof(temp));
    int dp(int i, int left, int n, int m , vector<int>&nums,  vector<int>&multipliers){
        if(i==m) return 0;
        int right=n-1-i+left;
        int multi = multipliers[i];
        if(temp[i][left]==0){
            temp[i][left]=max(multi*nums[left] + dp(i+1, left+1, n, m, nums, multipliers), multi*nums[right] + dp(i+1, left, n, m , nums, multipliers));
        }
        return temp[i][left];
    }
    
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n=nums.size();
        int m = multipliers.size();
        return dp(0,0, n, m , nums, multipliers);
    }
};