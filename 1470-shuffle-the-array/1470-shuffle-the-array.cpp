class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int l=0, r=n;
        vector<int>ans;
        while(l<n and r<2*n){
            ans.push_back(nums[l]);
            ans.push_back(nums[r]);
            l++;
            r++;
        }
        return ans;
    }
};