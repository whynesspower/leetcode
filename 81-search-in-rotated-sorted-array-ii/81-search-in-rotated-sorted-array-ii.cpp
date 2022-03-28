class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l= 0;
        int r=nums.size()-1;
        while(l<=r){
            int mid = (l+ r) >>1;
            if(nums[mid]==target) return true;
            if(nums[mid]==nums[l] and nums[mid]== nums[r]){
                l++;
                r--;
            }
            else if(nums[mid] >= nums[l]){
                if(target< nums[mid] and target>= nums[l] ){
                    r= mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            else{
                if(target> nums[mid] and target<= nums[r]){
                    l= mid+1;
                }
                else{
                    r= mid-1;
                }
            }
        }
        return false;
    }
};