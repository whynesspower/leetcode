#define ll long long 
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int n = spells.size();
        int m = potions.size();
        vector<int>ans(n, 0);
        for(ll i=0;i<n;i++){
            double t= ((double)success/(double)spells[i]);
            
            ll tt= ceil(t);
            
            auto it= lower_bound(potions.begin(), potions.end(), tt);
            if(it==potions.end()) continue;
            auto j= it-potions.begin();
            // cout<<t<<" "<<tt<<" "<<j<<endl;
            ans[i]= (m-j)>=0? m-j: 0;
        }
        return ans;
    }
};