class Solution {
public:
    vector<int>lps;
    void createLps(string &s){
        int i=1;
        int j=0;
        while(i<s.size()){
            if(s[i]==s[j]){
                lps[i]=j+1;
                i++;
                j++;
            }
            else{
                if(j==0){
                    lps[i]=0;
                    i++;
                }
                else{
                    j=lps[j-1];
                }
            }
        }
    }
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        lps.resize(n, 0);
        createLps(s);
        int m=lps[n-1];
        int l=n-m;
        if(m==0) return false;
        return m%l==0;
    }
};