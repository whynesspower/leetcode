class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n=s.size();
        vector<int>cnt1(n+1, 0), cnt0(n+1, 0);
        if(n<=1) return 0;
        int ans=INT_MAX;
        // cnt1[0]=(s[0]=='1'?1:0);
        for(int i=1;i<=n;i++){
            cnt1[i]=cnt1[i-1]+(s[i-1]=='1'?1:0);
        }
        // cnt0[n-1]=(s[n-1]=='0'?1: 0);
        for(int i=n-1;i>=0;i--){
            cnt0[i]=cnt0[i+1]+(s[i]=='0'?1:0);
        }
        for(int i=0;i<=n;i++){
            ans=min(ans, cnt1[i]+cnt0[i]);
        }
        
        return ans;
    }
};