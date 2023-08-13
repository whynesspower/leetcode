class Solution {
public:
    vector<int>dp;
    int n;
    // this function tells if the function 
    // has a valid from ith index and beyond.
    bool ifIndexIValid(vector<int>& nums, int i){
        if(i==nums.size()) return true;
        if(dp[i]!=-1) return dp[i];
        if(i+1<n && nums[i]==nums[i+1]){
            if(ifIndexIValid(nums, i+2)==true){
                dp[i]=true;
                return true;
            }
            if(i+2<n && nums[i]==nums[i+2]){
                if(ifIndexIValid(nums, i+3)==true){
                    dp[i]=true;
                    return true;
                }
            }
        }
        if(i+2<n and nums[i]==nums[i+1]-1 and nums[i]==nums[i+2]-2){
            if(ifIndexIValid(nums, i+3)){
                dp[i]=true;
                return true;
            }
        }
        return dp[i]=false;
    }
    
    bool validPartition(vector<int>& nums) {
        n=nums.size();
        dp.resize(n, -1);
        return ifIndexIValid(nums, 0);
    }
};