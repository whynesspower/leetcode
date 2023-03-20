class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        if(n==0) return true;
        int m = f.size();
        int cnt=0;
        if(m==1 and f[0]==0 and n==1) return true; 
        for(int i=0;i<m;i++){
            if(i+1< m and f[i]==0 and f[i+1]==0){
                cnt++;
                i++;
            } 
            else if(f[i]==1){
                i++;
                continue;
            }
            else if(i-1>=0 and f[i]==0 and f[i-1]==0 and i==m-1 ) cnt++;
        }
        if(cnt>=n) return true;
        return false;
    }
};