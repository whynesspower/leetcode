class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char,int>mp;
        int end=0, begin=0, ans=0, counter=0;
        
        while(end<s.size()){
            char a= s[end];
            mp[a]++;
            if(mp[a]>1){
                counter++;
            }
            end++;
            
            while(counter>0){
                char b= s[begin];
                if(mp[b]>1)counter--;
                mp[b]--;
                begin++;
            }
            ans=max(ans, end-begin);
        }
        return ans;
    }
};