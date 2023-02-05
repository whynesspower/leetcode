#define ll long long 
class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<ll,ll>mp,m1, m2;
        for(auto &x:basket1){
            mp[x]++;
            m1[x]++;
        }
        for(auto &x:basket2){
            mp[x]++;
            m2[x]++;
        }
        vector<ll>allEle;
        ll minx=INT_MAX;
        for(auto &x:mp){
            minx=min(minx, x.first);
            if(x.second%2!=0) return -1;
        }
        for(auto &x: m1){
            while(m1[x.first]>((mp[x.first])/2)){
                allEle.push_back(x.first);
                m1[x.first]--;
            }
        }
        for(auto &x: m2){
            while(m2[x.first]>(mp[x.first]/2)){
                allEle.push_back(x.first);
                m2[x.first]--;
            }
        }
        sort(allEle.begin(), allEle.end());
        ll ans=0;
        for(ll i=0;i<allEle.size()/2;i++){
            ans+=min(2*minx, allEle[i]);
        }
        return ans;
    }
};