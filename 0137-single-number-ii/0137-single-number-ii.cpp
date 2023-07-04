class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Time O(n)
        // Space O(1)
        
        
        // Approach: 5 mins
        // XOR all of them to get XOR of all elements if they appeared single time 
        // store above result in X
        // Now xor of all elements with X.
        unsigned int mask=(1<<31);
        unsigned int ans=0;
        while(mask){
            int c=0;
            for(int i=0;i<nums.size();i++){
                if(mask&nums[i]) c++;
            }
            c=c%3;
            if(c){
                ans=(ans|mask);
            }
            mask=(mask>>1);
        }
        
        return ans;
    
    }
};