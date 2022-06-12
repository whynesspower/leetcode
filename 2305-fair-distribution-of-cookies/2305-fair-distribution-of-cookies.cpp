class Solution {
public:
    int ans=INT_MAX;
    
    void helper(vector<int>&v, vector<int>&C, int k, int start){
        if(start==C.size()){
            int maxa=INT_MIN;
            for(int i=0;i<k;i++){
                maxa=max(v[i], maxa);
            }
            ans=min(ans, maxa);
            return;
        }
        
        for(int i=0;i<k;i++){
            v[i]+=C[start];
            helper(v, C, k,start+1);
            v[i]-=C[start];
        }
    }
    
    int distributeCookies(vector<int>& C, int k) {
        vector<int>v(k,0);
        helper(v, C, k, 0);
        return ans;
    }
};