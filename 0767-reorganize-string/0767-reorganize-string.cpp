class Solution {
public:
    string reorganizeString(string s) {
        vector<int>cnt(26, 0);
        int maxFreqElement=0;
        for(int i=0;i<s.size();i++){
            int currPos=s[i]-'a';
            cnt[currPos]++;
            if(cnt[currPos]>cnt[maxFreqElement]){
                maxFreqElement=currPos;
            }
        }
        if(cnt[maxFreqElement] > s.size()-cnt[maxFreqElement]+1){
            return "";
        }
        int i=0;
        while(cnt[maxFreqElement]){
            s[i]=(maxFreqElement+'a');
            i+=2;
            cnt[maxFreqElement]--;
        }
        for(int j=0;j<26;j++){
            while(cnt[j]){
                if(i>=s.size()) i=1;
                s[i]=(j+'a');
                i+=2;
                cnt[j]--;
            }
        }
        return s;
    }
};