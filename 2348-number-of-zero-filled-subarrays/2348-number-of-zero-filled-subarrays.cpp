#define ll long long 
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        ll currLen=0;
        ll ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                currLen=0;
            }
            else{
                ans+= currLen;
                currLen++;
                ans++;
            }
        }
        return ans;
    }
};