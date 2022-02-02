class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()==0 or t.size()==0 or t.size()> s.size()) return "";
        unordered_map<char,int>mp;
        for(int i=0;i<t.size();i++){
            mp[t[i]]++;
        }
        int counter=mp.size(), end=0, begin=0;
        int len=INT_MAX;
        int head;
        
        while(end<s.size()){
            char a= s[end];
            if(mp.find(a)!=mp.end()){
                mp[a]--;
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