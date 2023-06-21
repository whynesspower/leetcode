#define ll long long
​
​
class Solution {
public:
long long minCost(vector<int>& nums, vector<int>& cost) {
ll l=0, r=INT_MAX;
ll ans=solve(nums, cost, 1);
while(l<r){
ll x=l+(r-l)/2;
ll x1=solve(nums, cost, x);
ll x2=solve(nums, cost, x+1);
ans=min(x1, x2);
if(x1<x2){
r=x;
}
else{
l=x+1;
}
}
return ans;
}
// solve returns the cost to reach the element "X"
// as the median point.
ll solve(vector<int>&nums, vector<int>&cost,ll x ){
ll ans=0;
for(int i=0;i<nums.size();i++){
ans+= 1L*abs(nums[i]-x)*cost[i];
}
return ans;
}
};
​