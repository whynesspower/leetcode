class Solution {
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        
        unordered_map<char, int>mp;
        char y = 'a';
        for(int i=1;i<=26;i++){
            mp[y]=i;
            y++;
        }
        
        long long int res=0, n=s.size(), prod=1;
        for(int i=n-k;i<n;i++){
            res = res + mp[s[i]]*prod;
            if(i!=n-1)
            {
                prod= (prod*power)%modulo;
            }
        }
        
        int ans= n-k;
        
        for(int i = n-k-1;i>=0;i--){
            long long int sub = mp[s[i+k]]*(prod%modulo);
            res= res-sub;
            res%=modulo;
            res=res*(power%modulo);
            res+= mp[s[i]];
            while(res%modulo<0){
                res+=modulo;
            }
                                   
            if(hashValue==res%modulo){
                ans=i;
            }
        }
                                   
        return s.substr(ans, k);
    }
};