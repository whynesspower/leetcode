class Solution {
public:
    int maxVowels(string s, int k) {
        int ans=INT_MIN;
        int currcnt=0;
        unordered_set<char>st={'a', 'e', 'i', 'o', 'u'};
        int l=0, r=0;
        // int i=0;
        while(r<k){
            if(st.find(s[r])!=st.end()){
                currcnt++;
                ans=max(ans, currcnt);
            }
            r++;
        }
        while(r<s.size()){
            if(st.find(s[r])!=st.end()){
                currcnt++;
            }
            if(st.find(s[l])!=st.end()){
                currcnt--;
            }
            ans=max(ans, currcnt);
            r++;
            l++;
        }
        return ans;
    }
};