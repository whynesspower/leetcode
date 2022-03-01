class Solution {
public:

    vector<int> countBits(int n) {
        vector<int>ans(n+1);
        for(int i=0;i<=n;i++){
            FillArray(ans, i);
        }
        return ans;
    }
    
    void FillArray(vector<int>&ans, int i){
            int count=0;
            int j=i;
            while(j!=0){
                j=j&j-1;
                count++;
            }
            ans[i]=count;
    }
};