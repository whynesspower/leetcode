class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size()<=1) return false;
        int k=-1, j=-1;
        for(int i=0;i<s.size();i++){
            if(s[i]!=goal[i]){
                if(k==-1){
                    k=i;
                }
                else if(j==-1){
                    j=i;
                }
                else{
                    return false;
                }
            }
        }
        if(k==-1 || j==-1){
            if(k==-1 and j==-1){
                vector<int>cnt(26, 0);
                for(int i=0;i<s.size();i++){
                    cnt[s[i]-'a']++;
                }
                for(auto x:cnt){
                    if(x>=2) return true;
                }
            }
            return false;   
        }
        char a=s[k];
        s[k]=s[j];
        s[j]=a;
        if(s==goal) return true;
        else return false;
    }
};