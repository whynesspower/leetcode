class Solution {
public:
    vector<vector<double>>dp;
    
    double solve(int a , int b){
        if(dp[a][b]!=0) return dp[a][b];
        if(a==0 and b!=0) return 1.0;
        if(a==0 and b==0) return 0.5;
        if(a!=0  and b==0) return 0.0;
        double ans=0.0;
        ans+= 0.25*(solve(a-min(a, 100), b));
        ans+= 0.25*(solve(a-min(a, 75), b-min(b, 25)));
        ans+= 0.25*(solve(a-min(a, 50), b-min(b, 50)));
        ans+= 0.25*(solve(a-min(a, 25), b-min(b, 75)));
        dp[a][b]=ans;
        return ans;
    }
    
    double soupServings(int n){
        // observation found out that when we take 5000
        // ans comes out to be 0.99999 something which is so close to 1 
        // it is that close to one that it falls under the accepted error limit 
        // which is 10^-5
        // hence above 5000 answer can be returned just as 1. 
        
        if(n>=5000) return 1.0;
        dp.resize(5000, vector<double>(5000, 0.0));
        return solve(n, n);
    }
};