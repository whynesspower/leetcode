class Solution {
public:
    static bool cmp(vector<int>&a, vector<int>&b){
        return a[1]<b[1];
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        for(auto x: pairs){
            cout<<x[0]<<" "<<x[1]<<endl;
        }
        vector<int>dp(pairs.size(), 1);
        //dp[i] size of the longest chain starting from 
        // 0 till the ith index.
        
        // traverse the pairs from 0th index
        // for every index 'i' go from i-1 to 0
        
        
        
        
        for(int i=0;i<pairs.size();i++){
            int j=i-1;
            int cnt=1;
            int maxLenTillI=1;
            for(;j>=0;j--){
                int c=pairs[i][0];
                int d=pairs[i][1];
                int a=pairs[j][0];
                int b=pairs[j][1];
                if(b<c){
                    maxLenTillI=max(maxLenTillI, dp[j]+1);
                }
            }
            dp[i]=maxLenTillI;
        }
        for(auto x: dp)
        {
            cout<<x<<" ";
        }       
        int ans=*max_element(dp.begin(), dp.end());
        return ans;
    }
};