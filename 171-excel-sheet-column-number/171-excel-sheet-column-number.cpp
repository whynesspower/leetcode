class Solution {
public:
    int titleToNumber(string columnTitle) {
        unordered_map<char,int>mp;
        int i=1;
        for(char x='A';x<='Z';x++){
            mp[x]=i;
            i++;
        }
        
        int n=columnTitle.size();
        int ans=0;
        int j=0;
        while(j<n){
            ans+= (mp[columnTitle[j]]* pow(26, n-j-1));
            j++;
        }
        
        return ans;
    }
};