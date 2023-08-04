class Solution {
    private: 
        unordered_set<string>st;
        unordered_map<string, int>dp;
    public:
    bool wordBreak(string s, vector<string>& dict) {
        for(auto x: dict){
            st.insert(x);
        }
        return remainingStringValid(s);
        // this function tells if the rest of the remaining string after index 
        // i is valid or not. 
    }
    bool remainingStringValid(string s){
        if(s.size()==0) return true;
        if(dp.find(s)!=dp.end()) return dp[s];
        for(int i=1;i<=s.size();i++){
            string currStr= s.substr(0, i);
            if((st.find(currStr)!=st.end()) && (remainingStringValid(s.substr(i))) ){
                dp[s]=1;
                return true;
            }
        }
        dp[s]=0;
        return dp[s];
    }
};