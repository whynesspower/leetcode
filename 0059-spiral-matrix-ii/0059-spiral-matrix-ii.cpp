class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int cnt=1;
        int direction=1;
        int right=n-1, left=0, top=0, bottom=n-1;
        while(cnt<=n*n){
            if(direction==1){
                for(int i=left;i<=right;i++){
                    ans[top][i]=cnt;
                    cnt++;
                }
                top++;
                direction=2;
            }
            else if(direction==2){
                for(int j=top;j<=bottom;j++){
                    ans[j][right]=cnt++;
                }
                right--;
                direction=3;
            }
            else if(direction==3){
                for(int i=right;i>=left;i--){
                    ans[bottom][i]=cnt++;
                }
                bottom--;
                direction=4;
            }
            else{
                for(int j=bottom;j>=top;j--){
                    ans[j][left]=cnt++;
                    
                }
                left++;
                direction=1;
            }
        }
        return ans;
    }
};