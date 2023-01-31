class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_so_far=nums[0];
        int min_so_far=nums[0];
        int overall_max=nums[0];
        for(int i=1;i<nums.size();i++){
            int a = max(max_so_far*nums[i], max(nums[i], min_so_far*nums[i]));
            int b = min(max_so_far*nums[i], min(nums[i], min_so_far*nums[i]));
            max_so_far=a;
            min_so_far=b;
            overall_max=max(overall_max, max_so_far);
        }
        return overall_max;
    }
};