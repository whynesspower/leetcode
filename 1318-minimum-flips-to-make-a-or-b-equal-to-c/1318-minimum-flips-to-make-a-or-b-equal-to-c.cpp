#define ll long long 
class Solution {
public:
    int minFlips(int a, int b, int c) {
        int k= 1;
        int ans=0;
        for(int i=0;i<30;i++){
            k= 1<<i;
            
            if((c&k)!=0){
            
                if((a&k)==0 and (b&k)==0){
                    ans++;

                }                
            }
            else{
                if((a&k)!=0) ans++;
                if((b&k)!=0) ans++;
            }
        }
        return ans;
    }
};