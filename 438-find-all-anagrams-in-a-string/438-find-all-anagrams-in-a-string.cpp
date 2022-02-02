class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        unordered_map<char, int>mp;
        for(int i=0;i<p.size();i++){
            mp[p[i]]++;
        }
        
        int begin=0,end=0, counter=mp.size();
        
        while(end<s.size()){
            char a = s[end];
            if(mp.find(a)!=mp.end()){
                mp[a]--;
                if(mp[a]==0){
                    counter--;
                }
            }
            end++;
            while(counter==0){
                char b= s[begin];
                if(mp.find(b)!=mp.end()){
                    mp[b]++;
                    if(mp[b]>0) counter++;
                }
                if(end-begin==p.size()){
                    ans.push_back(begin);
                }
                begin++;
            }
        }
        
        return ans;
    }
};