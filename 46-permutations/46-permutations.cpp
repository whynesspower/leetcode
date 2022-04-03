class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        do{
            vector<int>temp;
            for(int i=0;i<nums.size();i++){
                temp.push_back(nums[i]);
            }
            ans.push_back(temp);
        }
        while(next_permutation(nums.begin(), nums.end()));
              
        return ans;
    }
};