class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        int n=p.size();
        int m=s.size();
        vector<int>v1(26, 0), v2(26,0);
        
        for(int i=0;i<n;i++) v1[p[i]-'a']++;
        int i=0;
        for(;i<m;i++){
            if(i<n){
                v2[s[i]-'a']++;
            }
            else{
                if(v1==v2){
                    ans.push_back(i-n);
                }
                v2[s[i]-'a']++;
                v2[s[i-n]-'a']--;
            }
        }        
        if(v1==v2){
            ans.push_back(i-n);
        }
        
        return ans;
    }
};