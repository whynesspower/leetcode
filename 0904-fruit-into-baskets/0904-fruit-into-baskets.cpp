class Solution {
public:
    int totalFruit(vector<int>& f) {
        int l=0, r=0;
        int ans=INT_MIN;
        unordered_map<int,int>mp;
        while(r<f.size()){
            if(mp.find(f[r])==mp.end()){
                if(mp.size()>=2){
                    while(mp.size()>=2){
                        mp[f[l]]--;
                        if(mp[f[l]]==0) mp.erase(f[l]);
                        l++;
                    }
                    mp[f[r]]++;
                    ans=max(ans, r-l+1);
                    r++;
                }
                else{
                    mp[f[r]]++;
                    ans=max(ans, r-l+1);
                    r++;
                }   
            }
            else{
                mp[f[r]]++;
                ans=max(ans, r-l+1);
                r++;
            }
        }
        return ans;
    }
};