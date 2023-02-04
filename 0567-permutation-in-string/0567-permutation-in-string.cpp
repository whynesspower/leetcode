class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
        vector<int>v1(26,0), v2(26,0);
        for(auto &s:s1){
            v1[s-'a']++;
        }
        int i=0;
        while(i<s1.size()){
            v2[s2[i]-'a']++;
            i++;
        }
        if(v1==v2) return true;
        // i++;
        for(;i<s2.size();i++){
            v2[s2[i]-'a']++;
            v2[s2[i-s1.size()]-'a']--;
            if(v1==v2) return true;
        }
        return false;
    }
};