class Solution {
public:
    
    unordered_map<int,int>mp;
    
    int func(int n){
        
        mp[0]=0;
        mp[1]=1;
        mp[2]=1;
        if(n<=2) return mp[n];
        
        if(mp.find(n)!=mp.end()) return mp[n];
        
        mp[n]= func(n-1)+func(n-2)+func(n-3);
        
        return mp[n];
    }
    
    
    int tribonacci(int n) {
        return func(n);   
    }
};