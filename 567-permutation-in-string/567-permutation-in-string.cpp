class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> goal(26),m2(26);
        for(auto x:s1) goal[x-'a']++;
        for(int i=0;i<s2.size();i++){
            m2[s2[i]-'a']++;
            if(i>=s1.size()) m2[s2[i-s1.size()]-'a']--;
            if(goal==m2) return true;
        }
        return false;
    }
};