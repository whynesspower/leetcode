class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        for(auto x:nums){
            if(i< 1 or x > nums[i-1]){
                nums[i++]=x;
            }
        }
        return i; 
    }
};