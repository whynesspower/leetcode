```
class Solution {
public:
vector<vector<int>>dp;
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
if(n>=5000) return 1.0;
dp.resize(5000, vector<int>(5000, 0));
return solve(n, n);
}
};