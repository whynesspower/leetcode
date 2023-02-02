class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        bool flag= true;
        unordered_map<char, int>mp;
        for(int i=0;i<order.size();i++){
            mp[order[i]]=i;
        }
        vector<string>temp=words;
        sort(words.begin(), words.end(), [&](const string a, const string b){
            if(a==b) return true;
            int i=0, j=0;
            while(i<a.size() and j<b.size()){
                if(a[i]==b[j]){
                    i++;
                    j++;
                }
                else{
                    break;
                }
            }
            if(i<a.size() and j<b.size()) return mp[a[i]]<mp[b[j]];
            return a.size()< b.size();
            // return solve();
        });
        for(int i=0;i<temp.size();i++){
            if(temp[i]!=words[i]) return false;
        }
        return flag;
    }
};