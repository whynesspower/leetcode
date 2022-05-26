class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans=0;
        int temp=1;
        int t =31;
        while(t){
            if(temp&n){
                ans++;
            }
            temp=1<<(32-t);
            t--;
        }
        if(temp&n) ans++;
        return ans;
    }
};