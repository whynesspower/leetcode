class Solution {
public:
    int arraySign(vector<int>& nums) {
        int a=0, b=0;
        for(auto x:nums){
            if(x==0){
                b++;
                return 0;
            }
            if(x<0){
                a++;
            }
        }
        if(a&1) return -1;
        return 1;
    }
};