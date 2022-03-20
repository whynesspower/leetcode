class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        vector<int>cnta(7, 0);
        vector<int>cntb(7, 0);
        vector<int>same(7, 0);
        int ans=tops.size();
        
        for(int i=0;i<tops.size();i++){
            cnta[tops[i]]++;
            cntb[bottoms[i]]++;
            if(tops[i]==bottoms[i]){
                same[tops[i]]++;
            }
        }
        
        int n=tops.size();
        for(int i=1;i<7;i++){
            if((cnta[i]+cntb[i]- same[i])==n){
                
                int minswap= min(cnta[i], cntb[i]) - same[i];
                ans=min(ans, minswap);
            }
        }
        
        
        return ans==n?-1:ans;
    }
};