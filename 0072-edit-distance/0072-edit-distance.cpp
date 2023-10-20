class Solution {
public:
    vector<vector<int>>dp;
    // gives  you the number of operations required
    // to make substrings (0.. i ) equals to substring(0...j)
    int solve(int n, int m, string & w1, string &w2, int i, int j){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(w1[i]==w2[j]){
            int an= solve(n, m, w1, w2, i-1, j-1);
            return dp[i][j]=an;
        } 
        int cnt=min(solve(n, m, w1, w2, i, j-1)+1,min(solve(n, m, w1, w2, i-1, j)+ 1, solve(n, m, w1, w2, i-1, j-1)+ 1));
        dp[i][j]=cnt;
        return cnt;
    }

//     We can calculate values of distance as follows:
// distance(a,b) = min(distance(a,b −1)+1,
// distance(a−1,b)+1,
// distance(a−1,b −1)+cost(a,b)).
// Here cost(a,b) = 0 if x[a] = y[b], and otherwise cost(a,b) = 1.
// The formula
// considers the following ways to edit the string x:
// • distance(a,b −1): insert a character at the end of x
// • distance(a−1,b): remove the last character from x
// • distance(a−1,b −1): match or modify the last character of x
    int minDistance(string word1, string word2) {
        if(word1.length()==0)
            return word2.length();
        if(word2.length()==0)
            return word1.length();
        int n=word1.size();
        int m=word2.size();
        dp.resize(n, vector<int>(m, -1));
        solve( n, m, word1, word2, n-1, m-1);
        return dp[n-1][m-1];
    }
};