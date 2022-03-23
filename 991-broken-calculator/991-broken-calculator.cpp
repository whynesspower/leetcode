class Solution {
public:
    int brokenCalc(int x, int y) {
        int ans=0;
        while(x< y){
            if(y&1){
                y++;
                ans++;
            }else{
                ans++;
                y=y/2;
            }
        }
        
        return ans + x-y;
    }
};