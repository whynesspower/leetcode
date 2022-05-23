class Solution {
public:
    int dp[601][101][101]={};
    
    int solve(vector<pair<int,int>>&a,int index,  int m, int n ){
        if((m==0 and n==0) or index==a.size() ){
            return 0;
            
        }
        if(dp[index][m][n]!=-1){
            return dp[index][m][n];
        }
        if(a[index].first > m or a[index].second >n){
            return dp[index][m][n]= solve(a, index+1, m,n);
        }
        int include= 1 + solve(a, index+1, m - a[index].first, n-a[index].second);
        int exclude= solve(a, index+1, m, n);
        
        return dp[index][m][n]=max(include, exclude);
    }
    
    
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>>a;
        memset(dp, -1, sizeof(dp));
        for(auto i:strs){
            int ones=0, zero=0;
            for(auto j:i){
                if(j=='1')ones++;
                else zero++;
            }
            a.push_back({zero, ones});
        }
        
        int ans= solve(a, 0, m ,n);
        return ans;
        
    }
};