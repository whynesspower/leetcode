class Solution {
public:
    bool detectCapitalUse(string word) {
        int n=word.size();
        int cptlcntr=0;
        for(int i=0;i<n;i++){
            if(word[i]>='A' and word[i]<='Z'){
                cptlcntr++;
            }
        }
        if(cptlcntr==n or cptlcntr==0){
            return true;
        }
        else if(cptlcntr==1 and (word[0]>='A' and word[0]<='Z')){
            return true;
        }
        
        
        return false;
    }
};