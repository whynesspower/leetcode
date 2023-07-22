class Solution {
public:
    double memo[26][26][101] = {}; 
    
    double dfs(int n, int k, int row, int column){
        if(row >= n || column >= n || row < 0 || column < 0) return 0;
        if(k==0) return 1;
        if(memo[row][column][k]) return memo[row][column][k];
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
        return dfs(n, k, row, column);
    }
};