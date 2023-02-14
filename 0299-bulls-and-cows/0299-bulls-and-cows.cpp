class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_set<int>st;
        unordered_map<int,int>mp;
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i]) st.insert(i);
        }
        for(int i=0;i<secret.size();i++){
            // if(secret[i]==guess[i]) st.insert(i);
            if(st.find(i)==st.end()){
                mp[secret[i]-'0']++;
            }
        }
        int y=0;
        int x=st.size();
        for(int i=0;i<secret.size();i++){
            // if(secret[i]==guess[i]) st.insert(i);
            if(st.find(i)!=st.end()){
                continue;
            }
            if(mp.find(guess[i]-'0')!=mp.end()){
                mp[guess[i]-'0']--;
                if(mp[guess[i]-'0']==0){
                    mp.erase(guess[i]-'0');
                }
                y++;
            }
        }
        string ans="";
        ans+=to_string(x);
        ans+="A";
        ans+=to_string(y);
        ans+="B";
        return ans;
    }
};