class Solution {
public:
    int mod=1e9 + 7;
    int countVowelPermutation(int n) {
        unordered_map<int, vector<int>>mp;
        // a e i o u 
        // 0 1 2 3 4
        mp[0]={1, 4, 2};
        mp[1]={0, 2};
        mp[2]={1,3};
        mp[3]={ 2};
        mp[4]={3, 2};
        
        vector<vector<int>>dp(n, vector<int>(5,0));   
        for(int j=0;j<5;j++){
            dp[0][j]=1;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<5;j++){
                for(auto x: mp[j]){
                    dp[i][j]=(dp[i][j]+dp[i-1][x])%mod;
                }
            }
        }
        int ans=0;
        for(int j=0;j<5;j++){
            ans=(ans+dp[n-1][j])%mod;
        }
        return ans;
    }
};