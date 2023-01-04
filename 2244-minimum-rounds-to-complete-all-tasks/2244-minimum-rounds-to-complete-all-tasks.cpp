class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int>mp;
        for(auto x:tasks){
            mp[x]++;
        }
        int ans=0;
        for(auto x:mp){
            int b=x.second;
            if(b==1) return -1;
            if(b%3==0) ans+=b/3;
            else if(b%3==1) ans+=((b-2)/3+ 2);
            else{
                ans+=b/3+1;
            }
        }
        return ans;
    }
};