class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans="";
        int i=n-1;
        int kk=k;
        char ch='a';
        unordered_map<int, char>mp;
        for(int i=1;i<=26; i++){
            mp[i]=ch;
            ch++;
        }
        
        while(i>=0){
            if((k-i)>=26){
                ans.push_back(mp[26]);
                i--;
                k=k-26;
            }       
            else{
                ans.push_back(mp[k-i]);
                
                k-=(k-i);
                i--;
            }
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};