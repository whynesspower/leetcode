class Solution {
public:
    

    
    bool wordPattern(string pattern, string s) {
        
        vector<string> words;
        map<char, string>mp;
        set<string>st;
        
        string item;
        stringstream iss(s);
        while (iss >> item)
            words.push_back(item);
        
        if (pattern.size() != words.size())
            return false;        
        for(int i=0;i<pattern.size();i++){    
            if(mp.find(pattern[i])!=mp.end()){
                if(mp[pattern[i]]!=words[i]){
                    return false;    
                }
            }else{
                if(st.count(words[i])>0) return false;
                mp[pattern[i]]=words[i];
                st.insert(words[i]);
            }
        }
        
        return true;
    }
};