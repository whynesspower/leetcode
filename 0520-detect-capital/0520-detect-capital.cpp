class Solution {
public:
    bool isCapital(char x){
        if(x>='A'&&x<='Z') return true;
        return false;
    }
    
    
    bool detectCapitalUse(string word) {
        int c=0;
        for(auto x:word){
            if(isCapital(x)) c++;
        }
        if(c==0 or c==word.size()) return true;
        if(c==1 and isCapital(word[0])) return true;
        return false;
    }
};