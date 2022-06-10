class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>mp;
        int l=0, r=0;
        int ans=INT_MIN;
        if(s.size()==0 or s.size()==1){
            return s.size();
        }
        while(r!=s.size()){
            if(mp.find(s[r])!=mp.end()){
                while(l<=mp[s[r]]){
                    mp.erase(s[l]);
                    l++;
                }
                // l=mp[s[r]]+1;
            }
            mp[s[r]]=r;
            r++;
            ans=max(ans, r-l);    
        }
        
        return ans;
    }
};