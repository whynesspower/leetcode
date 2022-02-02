class Solution {
public:
    int tribonacci(int n) {
        unordered_map<int,int>mp;
        mp[0]=0;
        mp[1]=1;
        mp[2]=1;
        for(int i=3;i<=n ;i++){
            mp[i]=mp[i-1]+mp[i-2]+mp[i-3];
        }
        return mp[n];
    }
};