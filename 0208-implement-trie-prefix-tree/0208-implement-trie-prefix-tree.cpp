class Trie {
public:
    unordered_map<string, pair<bool, bool>>mp;
    // string (prefixEnd, StringEnd)
    Trie() {
        
    }
    
    void insert(string word) {
        mp[word]={true, true};
            
        for(int i=1;i<=word.size();i++){
            string s=word.substr(0,i);
            if(mp.find(s)!=mp.end())continue;
            else{         
                mp[s]={true, false};   
            }
        }
    }
    
    bool search(string word) {
        if(mp.find(word)==mp.end()) return false;
        auto it= mp[word];
        if(it.second==true) return true;
        return false;
    }
    
    bool startsWith(string word) {
        if(mp.find(word)==mp.end()) return false;
        auto it= mp[word];
        if(it.first==true) return true;
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */