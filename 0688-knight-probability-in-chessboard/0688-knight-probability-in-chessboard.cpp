class Solution {
public:
    double memo[26][26][101] = {}; 
    
    double dfs(int n, int k, int row, int column){
        // if you are outside the board already
        // then probablity is 0 to be on the board
        if(row >= n || column >= n || row < 0 || column < 0) return 0;
        
        // if the above condition is false then you  below code will execute
        // if the value of remaining moves is 0, then probablity of staying
        // on the board is 1
        if(k==0) return 1;
        
        // memoizing the solution 
        if(memo[row][column][k]) return memo[row][column][k];
        
        // summing up the probablity 
        double prob = 0;
        prob += dfs(n, k-1, row-1, column-2);
        prob += dfs(n, k-1, row-2, column-1);
        prob += dfs(n, k-1, row-2, column+1);
        prob += dfs(n, k-1, row-1, column+2);
        prob += dfs(n, k-1, row+1, column+2);
        prob += dfs(n, k-1, row+2, column+1);
        prob += dfs(n, k-1, row+2, column-1);
        prob += dfs(n, k-1, row+1, column-2);
        prob /= 8;
        return memo[row][column][k] = prob;
    }
    
    double knightProbability(int n, int k, int row, int column) {
        // dfs will return the probablity of staying on the board
        // given that you are at rth row, and cth column
        // and you have k moves left
        return dfs(n, k, row, column);
    }
};