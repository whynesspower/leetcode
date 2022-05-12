class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        helper(nums,0, nums.size());
        return ans;
    }
    void helper(vector<int>nums,int i, int j){
        if(i==j-1){
            ans.push_back(nums);
            return;   
            
        }
        for(int k=i;k<j;k++){
            if(i!=k and nums[i]==nums[k])continue;
            swap(nums[i], nums[k]);
            helper(nums, i+1, j);
        }
    }
};