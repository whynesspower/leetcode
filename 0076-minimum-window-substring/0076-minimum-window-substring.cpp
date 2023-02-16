class Solution {
public:
    string minWindow(string s, string t) {
        // this is question is pretty straight foreward
        // the implementation is a little difficult
        if(s.size()==0 or t.size()==0 or t.size()> s.size()) return "";
        unordered_map<char,int>mp;
        for(int i=0;i<t.size();i++){
            mp[t[i]]++;// store the count of from the string "T"
        }
        int counter=mp.size(), end=0, begin=0;
        int len=INT_MAX;
        int head;
        // counter ==0 means the substring under considerration 
        // does not need any more char and it is equivalent to 
        // the string "T"
        while(end<s.size()){
            char a= s[end];
            if(mp.find(a)!=mp.end()){
                mp[a]--;
                // counter is reduced which means that current 
                // char has been found with all of its frequncies
                if(mp[a]==0)counter--;
            }
            
            end++;
            while(counter==0){
                char b= s[begin];
                if(mp.find(b)!=mp.end()){
                    mp[b]++;
                    if(mp[b]>0){
                        counter++;
                    }
                    // a positive counter means that 
                    // we need to search for a certain character 
                    // of s[begin]
                }
                if(end-begin < len){
                    len=end-begin;
                    head=begin;
                }
                
                begin++;
            }
        }
        if(len==INT_MAX) return "";
        return s.substr(head, len);
    }
};