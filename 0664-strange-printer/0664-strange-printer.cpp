class Solution {
public:
    int strangePrinter(string s) {
        int n=s.size();
        if(n==0){
            return 0;
        }
        // Dp of i,j will return the answer 
        // which is the min number of stores needed to print from index i to j of the string
        vector<vector<int>>dp(n, vector<int>(n));
        for(int i=0;i<n;i++){
            // base case 
            dp[i][i]=1;
            if(i<n-1){
                // if ith index is equals to the i+1th index then 
                // number of strokes req is 1 else 2
                dp[i][i+1]=s[i]==s[i+1]?1:2;
            }
        }
        
        // for every possible length of the string
        for(int len=2;len<n;len++){
            // for length 'len' start from 0 to max possible 
            for(int start=0;start+len<n;start++){
                // we know by default the max possible strokes req to print
                // is the len number of strokes 
                dp[start][start+len]=len+1;
                for(int k=0;k<len;k++){
                    // we divide each possible length in to each possible fraction
                    // lets chose 'k' as the dividing index
                    int currdist=dp[start][start+k] + dp[start+k+1][start+len];
                        // above line is the by default answer
                    dp[start][start+len]=min(dp[start][start+len], s[start+k]==s[start+len]?currdist-1: currdist);
                    // suppose char at 'start+k' is equals to 'start+len'
                    // then it means they can be drawn with only stroke.
                }
            }
        }
        // final answer
        return dp[0][n-1];
    }
};