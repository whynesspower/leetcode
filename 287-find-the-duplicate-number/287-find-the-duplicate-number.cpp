class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1;
        int high = nums.size()-1;
        while(low < high){
            int mid = low+ (high-low)/2;
            int counter=0;
            for(auto x:nums){
                if(x<=mid){
                    counter++;
                }
            }
            if(counter<=mid){
                low= mid+1;
            }
            else{
                high= mid;
            }
        }
        return low;
    }
};