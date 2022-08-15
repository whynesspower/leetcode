class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int>mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        unordered_map<string, int>mp2;
        mp2["IV"]=4;
        mp2["IX"]=9;
        mp2["XL"]=40;
        mp2["XC"]=90;
        mp2["CD"]=400;
        mp2["CM"]=900;
        int ans=0, i=0;
        int n=s.size();
        bool flag=false;
            while(i+1< n){
                string a = s.substr(i, 2);
                if(mp2.find(a)!=mp2.end()){
                        ans+= mp2[a];
                        if(i+1==n-1){
                            flag=true; 
                            break;
                        }
                    i=i+2;
                }
                else{
                    ans+= mp[s[i]];
                    i++;
                }
            }
        if(!flag){
            ans+= mp[s[n-1]];
        }
        
        
        return ans;
    }
};