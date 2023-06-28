class Solution {
public:
    string removeDuplicates(string s) {
        int j=0;
        int n=s.size();
        vector<int>cnt(n, 1);
        for(int i=0;i<n;i++, j++){
            s[j]=s[i];
            if(j>0 and s[j]==s[j-1]){
                cnt[j]=cnt[j-1]+1;
            }
            else cnt[j]=1;
            if(cnt[j]==2){
                j-=2;
            }
        }
        return s.substr(0, j);
        
    }
};