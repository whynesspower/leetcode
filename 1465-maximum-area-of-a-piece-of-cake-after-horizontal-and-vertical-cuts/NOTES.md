```
class Solution {
public:
int maxArea(int hh, int ww, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
sort(horizontalCuts.begin(), horizontalCuts.end());
sort(verticalCuts.begin()  , verticalCuts.end());
auto MOD= 1000000007;
auto h=(verticalCuts[0]-0)%MOD;
auto w=(horizontalCuts[0]-0)%MOD;
for(auto  i=1;i<verticalCuts.size();i++){
auto tempht=(verticalCuts[i]-verticalCuts[i-1])%MOD;
h=max(h,tempht )%MOD;
}
h=max(h,ww- verticalCuts[verticalCuts.size()-1])%MOD;
for(auto i=1;i<horizontalCuts.size();i++){
auto  tempwd=(horizontalCuts[i]-horizontalCuts[i-1])%MOD;
w=max(w, tempwd)%MOD;
}
w=max(w,hh- horizontalCuts[horizontalCuts.size()-1])%MOD;
return (long)(w*h)%MOD;
}
};
​
​
​
```