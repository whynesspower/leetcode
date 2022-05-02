class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int a = 0, b=nums.size()-1;
        while(a < b){
            if((nums[b]&1)==0 and ((nums[a]&1)==1)){
                swap(nums[b], nums[a]);
                b--;
                a++;
            }
            else if((nums[b]&1)==1 and (nums[a]&1)==0){
                b--;
                a++;
            }
            else if((nums[b]&1)==0 and (nums[a]&1)==0){
                a++;
            }
            else if((nums[b]&1)==1 and (nums[a]&1)==1){
                b--;
            }
        }
        return nums;
    }
};