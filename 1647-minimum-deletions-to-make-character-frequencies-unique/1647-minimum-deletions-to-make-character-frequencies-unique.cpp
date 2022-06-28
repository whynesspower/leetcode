class Solution {
public:
    int minDeletions(string s) {
        int ans=0;
        unordered_map<char, int>mp;
        
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        
        unordered_set<int>st;
        // for(auto it:mp){
        //     st.insert(it.second);
        // }
        
        for(auto it:mp){
            while(st.find(it.second)!=st.end()){
                it.second--;
                ans++;
                if(it.second==0) break;
            }
            st.insert(it.second);
        }
        
        return ans;
    }
};