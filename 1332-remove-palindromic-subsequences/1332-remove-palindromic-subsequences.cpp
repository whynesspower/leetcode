class Solution {
public:
    int removePalindromeSub(string s) {
        bool flag=true;
        int l=0, high=s.size()-1;
        while(high>l){
            if(s[l++]!=s[high--]){
                flag=false;
                break;
            }
        }
        return flag?1:2;
    }
};