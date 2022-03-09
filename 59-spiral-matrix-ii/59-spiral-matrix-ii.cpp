class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int counter=1;
        vector<vector<int>> ans( n , vector<int> (n, 0));
    
        int m=n;
        int top=0, left=0, down=n-1, right=n-1;
        int direc=0;
        
        while(top<=down and left<=right){
            if(direc==0){
                for(int i=left;i<=right;i++){
                    ans[top][i]=counter++;
                }
                top++;
            }
            else if(direc==1){
                for(int i=top;i<=down;i++){
                    ans[i][right]=counter++;
                }
                right--;
            }
            else if(direc==2){
                for(int i=right;i>=left;i--){
                    ans[down][i]=counter++;
                }
                down--;
            }
            else{
                for(int i=down;i>=top;i--){
                    ans[i][left]=counter++;
                    
                }
                left++;
            }
            direc=(direc+1)%4;
        }
        return ans;
    }
};