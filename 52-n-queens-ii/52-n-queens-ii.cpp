class Solution {
public:
    int ans=0;
    vector<vector<int>>result;
    int row[10];
    bool issafe(int r, int c){
        for(int i=0;i<c;i++){
            if(row[i]==r or (abs(row[i]-r)==abs(i-c))){
                return false;
            }
        }
        return true;
    }
    
    
    void solve(int c, int n){
        if(n==2 or n==3) return ;
        if(c==n){
            ans++;
        }
        for(int i=0;i<n;i++){
            if(issafe(i,c)){
                row[c]=i;
                solve(c+1, n);
            }
        }
    }
    
    
    int totalNQueens(int n) {
        result.clear();
        solve(0, n);
        return ans;
    }
};