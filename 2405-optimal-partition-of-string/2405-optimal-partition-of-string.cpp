class Solution {
public:
    int partitionString(string s) {
        vector<int>vis(26,0);
        vis[s[0]-'a']++;
        int ans=1;
        for(int i=1;i<s.size();i++){
            if(vis[s[i]-'a']!=0){
                ans++;
                vis.clear();
                vis.resize(26,0);
                vis[s[i]-'a']++;
            }
            else{
                vis[s[i]-'a']++;
            }
        }
        return ans;
    }
};