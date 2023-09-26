class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_set<char>vis;
        unordered_map<char, int>mp;
        for(auto x:s){
            mp[x]++;
        }
        string ans="0";
        int n=s.size();
        for(int i=0;i<n;i++){
            mp[s[i]]--;
            if(mp[s[i]]==0) mp.erase(s[i]);

            if(vis.find(s[i])!=vis.end()){
                continue;
            }
            while(s[i]<ans.back() and mp[ans.back()]>0){
                vis.erase(ans.back());
                ans.pop_back();
            }
            ans+=s[i];
            vis.insert(s[i]);
        }
        return ans.substr(1);
    }
};