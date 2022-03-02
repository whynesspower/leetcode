class Solution {
public:
    bool isSubsequence(string s, string t) {
        return temp(s, t, s.size(), t.size());
        
    }
private: 
    bool temp(string &s, string &t, int n, int m){
        
        if(n==0){
            return true;
        }
        if(m==0){
            return false;
        }
        if(s[n-1]==t[m-1]){
            return temp(s, t, n-1, m-1);
        }else{
            return temp(s, t, n,m-1);
        }

    }
};