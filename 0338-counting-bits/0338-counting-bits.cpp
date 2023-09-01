class Solution {
public:
    void countSetOnes(vector<int>&ans, int num){
        int cnt=0;
        int mask=1;
        for(int i=0;i<31;i++){
            mask=1<<i;
            if(num&mask){
                cnt++;
            }
        }
        ans.push_back(cnt);
    }
     
    
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0;i<=n;i++){
            countSetOnes(ans, i);
        }
        return ans;
    }
};